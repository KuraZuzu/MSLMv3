/*!
* @file Motor.h v1.0
* @Copyright © 2018 Kazushi Kurasawa
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/

#ifndef NEWZUZUMOUSE_MOTOR_H
#define NEWZUZUMOUSE_MOTOR_H

#include "deftype.h"
#include "vector.h"
#include "point.h"
#include "mbed.h"

class StepMotor{

private:
    DigitalOut _clock;
    DigitalOut _reset;
    DigitalOut _wise;
    DigitalOut _m3;
    int64_t _pulse_count;
    bool _forward_wise;

public:
    //モータの仕様書より、「クロック」「リセット」「wise」「デフォルト回転方向(これは自分定義)」「m3」の各ピンをいれる
    StepMotor(PinName clock, PinName reset, PinName wise, bool default_wise, PinName m3);

    void set_m3(bool m3); //m3(モータドライバの起動フラグ)のセット

    void step(); //ステップ(ステッピングモータ)を刻むことで、モータが回る

    void reset_count(); // 自己位置推定をするモータのステップカウントをリセット

    void pulse_counter(); // 自己位置推定をするモータのステップ(パルス)数をカウンｔ

    int64_t pulse_counts();

    void set_wise(bool wise);
    bool get_wise(){
        return _wise==_forward_wise;
    }

};



class MotorManager{


private:

    StepMotor _left_motor;
    StepMotor _right_motor;
    AnalogOut RefOut;
    Ticker run;
    double_t _l_speed{0.0};
    double_t _r_speed{0.0};
    timestamp_t l_t{0};
    timestamp_t r_t{0};
    bool l_flag{false};
    bool r_flag{false};

    int32_t old_l_pulse;
    int32_t old_r_pulse;
    int32_t delta_l_pulse;
    int32_t delta_r_pulse;
    int32_t l_pulse;
    int32_t r_pulse;
    double_t delta_l_distance;
    double_t delta_r_distance;
    double_t v;

    unsigned int odometry_watch_count;
    char current_machine_direction = 0;  //0:北  1:東  2:南  3:西  4:南
    int v_count;

public:
    Position _position;

    MotorManager(StepMotor left, StepMotor right, PinName refout); //呼び出し

    void set_left_speed(double_t l_speed); //左モータを mm/s の物理量で速度指定
    void set_right_speed(double_t r_speed); // 右モータ。左モータと内容は同じ
    void set_odometry_watch_count(unsigned int odometry_count); // オドメトリデバッグモードの数値をいじるチートモード
    unsigned int get_odometry_watch_count(); // オドメトリのデバッグ監視用
    char get_current_machine_direction(); //現在のオドメトリにおいて、自機の向いている方向を返す

    double_t left_distance();  //左モータ の進んだ距離を返す
    double_t right_distance(); //右モータ "
    int64_t distance_counts(); //自機の中心点の進んだ距離を返す。左右のモーターの平均値で計算。

    void reset_counts(); //オドメトリに用いるモータ の回転数のパルスカウントをリセット

    void loop(); // モータを指定するまでループすることでパルスを刻み続ける親となるループ
    void init(timestamp_t tick_speed=25);  //タイマ割り込みのスピード、"25μs" (10usは早すぎて無理だった)

    void kill();      //割り込み自体を停止する
    void motor_on();  //モータの制御開始
    void motor_off(); //モータの制御停止

};

#endif //NEWZUZUMOUSE_MOTOR_H