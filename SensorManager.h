//
// Created by 倉澤　一詩 on 2018/11/27.
//

#ifndef NEWZUZUMOUSE_SENSORMANAGER_H
#define NEWZUZUMOUSE_SENSORMANAGER_H

#include "deftype.h"
#include "mbed.h"
#include "sensor.h"


#define WALL_TH 170.0

class SensorManager {

    DistanceSensor left_sensor, front_sensor, right_sensor;


public:

    SensorManager(PinName _left, PinName _front, PinName _right):left_sensor(_left), front_sensor(_front), right_sensor(_right){

    };

    inline bool is_opened_left_wall() {
        return left_sensor >= WALL_TH;
    }

    inline bool is_opened_center_wall() {
        return front_sensor >= WALL_TH;
    }

    inline bool is_opened_right_wall() {
        return right_sensor >= WALL_TH;
    }

    inline int get_front_wall_distance() {
        return front_sensor;
    }

    inline int get_left_wall_distance() {
        return left_sensor;
    }

    inline int get_right_wall_distance() {
        return right_sensor;
    }


};


#endif //NEWZUZUMOUSE_SENSORMANAGER_H
