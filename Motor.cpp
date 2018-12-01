//
// Created by 倉澤　一詩 on 2018/09/22.
//
#include "Motor.h"
#include "deftype.h"
#include "../defines.h"

//コンストラクタ
StepMotor::StepMotor(PinName clock, PinName reset, PinName wise, bool default_wise, PinName m3):
_clock(clock, false), _m3(m3, true), _wise(wise, default_wise), _reset(reset, false) {

    _forward_wise = default_wise;
    _pulse_count = 0;
}



void StepMotor::step(){
    _clock = !_clock;
    pulse_counter();
}



void StepMotor::pulse_counter(){
    if(_forward_wise == _wise.read())
        _pulse_count++;
    else
        _pulse_count--;
}

int64_t StepMotor::pulse_counts(){
    return _pulse_count;
}

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

MotorManager::MotorManager(StepMotor left, StepMotor right, PinName refout) :
        _left_motor(left), _right_motor(right), RefOut(refout){

    v_count = 0;
    odometry_watch_count = 0;
    RefOut.write(static_cast<float>(0.08 / 3.3));
    l_flag = false;
    r_flag = false;
}


void MotorManager::set_left_speed(double_t l_speed) {

    l_flag = static_cast<bool>(l_speed);
    if(l_speed < 0.0){
        l_speed = -l_speed;
        _left_motor.set_wise(false);
    } else{
        _left_motor.set_wise(true);
    }

//    _l_speed = 180 * 55 / /l_speed;  //180mm進んで欲しい時に55回、回ったらモータが起動してほしい
//    _l_speed = 24 * 88 / l_speed;  //タイヤ全周88mmで400パルス欲しい(立ち上がりと立ち下がり分) 50usの時
//    _l_speed = 125 * 88 / l_speed; //10usの時
    _l_speed = 50 * 88 / l_speed;

}

void MotorManager::set_right_speed(double_t r_speed) {

    r_flag = static_cast<bool>(r_speed);
    if(r_speed < 0.0){
        r_speed = -r_speed;
        _right_motor.set_wise(false);
    } else{
        _right_motor.set_wise(true);
    }

//    _r_speed = 25 * 88 / r_speed;  //25回　タイヤの全周88mm　1(結果2)パルスで1.8度　一周400パルス 50us
//    _r_speed = 125 * 88 / r_speed;  //1 0us時
    _r_speed = 50 * 88 / r_speed;   //計算結果の参考として、set_left_spped(180)とした時には 24となる
}


double_t MotorManager::left_distance() {
    return _left_motor.pulse_counts() / (2000.0/218.0);
}

double_t MotorManager::right_distance() {
    return _right_motor.pulse_counts() / (2000.0/218.0);
}

void MotorManager::loop() {

////    if (v_count == 0)
////        odometry_watch_count = 0;

    if ((_l_speed <= l_t) && l_flag) {
        _left_motor.step();   //一回通過で1パルス(立ち上がりor立ち下がりのみなので、1パルスのみでは動いてない)
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



//    v_count++;  //サンプリングレートのためのカウント

    if (v_count == 400) {  // 25us * 400 = 10000us のサンプリングレートとなる (0.01s となる)

        delta_l_pulse = l_pulse - old_l_pulse;
        delta_r_pulse = r_pulse - old_r_pulse;


        old_l_pulse = l_pulse;
        old_r_pulse = r_pulse;

        //タイヤのスペックは、直径28.0mm、モーターが1セットのパルス(2pulse)で0.9度回転

        delta_l_distance = (delta_l_pulse) * 28.0 * PI / 400 / 2;   //　"/ 400"は,(360/0.9)であり、モーター2パルスの1回転に対する割合が "/ 2"  (0.9 or 1.8  ?)
        delta_r_distance = (delta_r_pulse) * 28.0 * PI / 400 / 2;   //　10ms = 0.01sごとの変化した距離(mm)がわかる.

        v = ( delta_l_distance + delta_r_distance ) * 100 / 2;

        _position.rad += (delta_r_distance - delta_l_distance) / WIDTH;//a  77.7

//        const double_t true_y = pow(delta_r_distance - delta_l_distance, 2.0);
//        const double_t true_x = (77.7 * 77.7) - true_y;
//        _position.rad += atan2(true_y, true_x); //WIDTH 77.7  //最初の引数は (角速度)ω * (サンプリングレート)Δt をかけた結果と同様であり、オドメトリのための角度計算で用いる


        _position.x += v * cos(PI/2 + _position.rad) / 100 ; // * 1.07;  //x軸  *(90/96)は、誤差のフィルターとして実装
        _position.y += v * sin(PI/2 + _position.rad) / 100;  //y軸  *(630/631)は、誤差のフィルターとして実装


        odometry_watch_count++;
        v_count = 0;
    }

    v_count++;
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
