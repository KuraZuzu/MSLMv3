/*!
* @file Motor.cpp v1.0
* @Copyright © 2018 Kazushi Kurasawa
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/
#include "motor.h"
#include "deftype.h"
#include "../defines.h"

StepMotor::StepMotor(PinName clock, PinName reset, PinName wise, bool default_wise, PinName m3):
_clock(clock, false), _reset(reset, false), _wise(wise, default_wise), _m3(m3, true) {

    _forward_wise = default_wise; // 前進の方向を、コンストラクタ 引数のデフォルト方向で代入
    _pulse_count = 0; // パルスのカウントを"0"で初期化
}


void StepMotor::step(){
    _clock = !_clock; // クロックの立ち上がりタイミングでモータがステップ単位で回転する
    pulse_counter();  // モータ を回した文のステップをカウント
}


/**
 * @fn 回転方向が正転ならパルスカウントを増加、逆転なら減らす
 */
void StepMotor::pulse_counter(){
    if(_forward_wise == _wise.read())
        _pulse_count++;
    else
        _pulse_count--;
}


/**
 * @fn 現在のパルス数を返す
 */
int64_t StepMotor::pulse_counts(){
    return _pulse_count;
}


/**
 * @fnmbedフレームワーク では write() で代入
 */
void StepMotor::set_m3(bool m3) {
    _m3.write(m3);
}


void StepMotor::set_wise(bool wise) {

    if(wise) {
        _wise = _forward_wise;
    }else{
        _wise = !_forward_wise;
    }

}


void StepMotor::reset_count() {
    _pulse_count = 0;
}


/**
 * @fn 左右のモータ で必要なピンを代入、"RefOut"では、電流量制御
 */
MotorManager::MotorManager(StepMotor left, StepMotor right, PinName refout) :
        _left_motor(left), _right_motor(right), RefOut(refout){

    v_count = 0; // v(速度)のカウント
    odometry_watch_count = 0; // オドメトリの監視用カウント
    RefOut.write(static_cast<float>(0.08 / 3.3)); // "0 ~ 1.0"での電流量指定。
                                                        //電源が "3.3v" なので、0.08Aを指定する式として "0.08/3.3"
    l_flag = false; // 左モータ のフラグを初期では"fasle"
    r_flag = false; // 右モータ のフラグを初期では"fasle"
}


/**
 * @fn 左モータ の速度を指定
 */
void MotorManager::set_left_speed(double_t l_speed) {

    l_flag = static_cast<bool>(l_speed); //速度が"0"であると、"false"となる
    if(l_speed < 0.0){        //速度指定が負の値だとモータ逆転
        l_speed = -l_speed;
        _left_motor.set_wise(false); //逆転
    } else{
        _left_motor.set_wise(true); //正転
    }

    _l_speed = 50 * 88 / l_speed; //タイヤ全周88mmで400パルス欲しい(立ち上がりと立ち下がり分)
    //25μsでの割り込みは固定。そして、2回につき1ステップ。これで "mm/s" の物理量に
}


/**
 * @fn 右モータ と同様
 */
void MotorManager::set_right_speed(double_t r_speed) {

    r_flag = static_cast<bool>(r_speed);
    if(r_speed < 0.0){
        r_speed = -r_speed;
        _right_motor.set_wise(false);
    } else{
        _right_motor.set_wise(true);
    }
    _r_speed = 50 * 88 / r_speed;
}


double_t MotorManager::left_distance() {
    return _left_motor.pulse_counts() / (2000.0/218.0);
}

double_t MotorManager::right_distance() {
    return _right_motor.pulse_counts() / (2000.0/218.0);
}



/**
 * @fn
 *   左右のモータで独立した割り込みを使用すると、タイマ のカウントにズレが発生する
 *   理由としては、ARM社の提供するフレームワーク "mbed"には抽象化のために、使えるタイマ は１つのみであるからだ。
 *   １つのタイマ を作動させておき、左右のモータ の速度差から、クロック(回転)をかける回数を区別する。
 *   １つのタイマ のみの使用となるので、ズレは発生しなくなるアルゴリズムとなる。
 */
void MotorManager::loop() {

    if ((_l_speed <= l_t) && l_flag) {
        _left_motor.step();   // 一回通過で1パルス(立ち上がりor立ち下がりのみなので、1パルスのみでは動いてない)
        l_t = 0;
        if(_left_motor.get_wise())
            l_pulse++;
        else
            l_pulse--;

    } else {
        l_t++;
    }


    if ((_r_speed <= r_t) && r_flag) {
        _right_motor.step();
        r_t = 0;
        if(_right_motor.get_wise())
            r_pulse++;
        else
            r_pulse--;

    } else{
        r_t++;
    }

    /* ここで、速度・走行距離の計測と自己位置推定を行う。
       タイマを"25μs"に設定してあるので、400回目のカウントで"0.01s"のサンプリングレートとなる */
    if (v_count == 400) {  // 25us * 400 = 10000μs (0.01s)

        delta_l_pulse = l_pulse - old_l_pulse; /*　モータへの回転指令数の差分を計測 */
        delta_r_pulse = r_pulse - old_r_pulse; /*　                            */

        old_l_pulse = l_pulse; /* 次回の計測のために、値を更新 */
        old_r_pulse = r_pulse; /*                         */

        // タイヤのスペックは、直径28.0mm、モーターが1セットのパルス(2pulse)で0.9度回転
        delta_l_distance = (delta_l_pulse) * 30.0 * PI / 400 / 2;   /*　"/ 400" は,(360/0.9)であり、モーター2パルスの1回転に対する割合が "/ 2" */
        delta_r_distance = (delta_r_pulse) * 30.0 * PI / 400 / 2;   /*　10ms = 0.01sごとの変化した距離(mm)がわかる.                         */

        v = ( delta_l_distance + delta_r_distance ) * 100 / 2;  //速度計測ｗ行う

        _position.rad += (delta_r_distance - delta_l_distance) / WIDTH;//　車幅と左右のモータ差分から、機体の角度(曲座標系)で計算
        //オドメトリの計算として用いる

        _position.x += v * cos(PI/2 + _position.rad) / 100; // * 1.07;  //x軸  *(90/96)は、誤差のフィルターとして実装
        _position.y += v * sin(PI/2 + _position.rad) / 100; //y軸  *(630/631)は、誤差の簡易的なフィルター(オペレータ)として実装

        odometry_watch_count++; //オドメトリのデバッグ用のカウント
        v_count = 0;            // タイマのカウント回数をリセット
    }

    v_count++; // 25μsごとにタイマが回るので、25μsごとにインクリメントされる
}

char MotorManager::get_current_machine_direction() {
    return current_machine_direction;
}

void MotorManager::set_odometry_watch_count(unsigned int odometry_count) {
    odometry_watch_count = odometry_count;
}

unsigned int MotorManager::get_odometry_watch_count() {
    return odometry_watch_count;
}


void MotorManager::init(timestamp_t tick_speed) {
    run.attach_us(this, &MotorManager::loop, tick_speed);
}

void MotorManager::kill() {
    run.detach();
}

void MotorManager::reset_counts() {
    _left_motor.reset_count();
    _right_motor.reset_count();
}

void MotorManager::motor_on() {
    _left_motor.set_m3(false);
    _right_motor.set_m3(false);
}

void MotorManager::motor_off() {
    _left_motor.set_m3(true);
    _right_motor.set_m3(true);
}

int64_t MotorManager::distance_counts() {
    return (int64_t)(left_distance() + right_distance()) / 2;
}
