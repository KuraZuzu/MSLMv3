//
// Created by 倉澤　一詩 on 2018/11/27.
//

#ifndef NEWZUZUMOUSE_SENSORMANAGER_H
#define NEWZUZUMOUSE_SENSORMANAGER_H

#include "deftype.h"
#include "mbed.h"
#include "sensor.h"
#include "vector.h"
#include "../defines.h"

#define MEAN_SIZE 5

class SensorManager {

    DistanceSensor left_sensor, front_sensor, right_sensor;
//    Vector<int32_t> ls,rs,fs;

public:

    SensorManager(PinName _left, PinName _front, PinName _right):left_sensor(_left), front_sensor(_front), right_sensor(_right){

    };

    inline bool is_opened_left_wall() {
        int32_t  mean=0;
        for (int i = 0; i < MEAN_SIZE; ++i) {
//            ls.push_back(left_sensor);
            mean += left_sensor;
        }
        mean = mean / MEAN_SIZE;

        return mean >= WALL_TH;
    }

    inline bool is_opened_front_wall() {
        int32_t mean =0;
        for (int i = 0; i < MEAN_SIZE; ++i) {
            mean += front_sensor;
        }
        mean = mean / MEAN_SIZE;

        return mean >= WALL_TH;
    }

    inline bool is_opened_right_wall() {
        int32_t mean = 0;
        for (int i = 0; i < MEAN_SIZE; ++i) {
            mean += right_sensor;

        }
        mean = mean / MEAN_SIZE;

        return mean >= WALL_TH;
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
