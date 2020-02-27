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

#define MEAN_SIZE 20 //平均値を取るための、センサ距離取得回数

class SensorManager {

    DistanceSensor left_sensor, front_sensor, right_sensor;


public:

    SensorManager(PinName _left, PinName _front, PinName _right):left_sensor(_left), front_sensor(_front), right_sensor(_right){

    };


/* 左センサが閾値を超えているかで、壁の設置の有無を返す */
    inline bool is_opened_left_wall() {
        int32_t  mean=0;
        //センサのノイズを打ち消すため、複数回の距離センサを作動させ、その平均値を取る
        for (int i = 0; i < MEAN_SIZE; ++i) {
            mean += left_sensor;
        }
        mean = mean / MEAN_SIZE;

        return mean >= WALL_TH;
    }


/* 左センサが閾値を超えているかで、壁の設置の有無を返す */
    inline bool is_opened_front_wall() {
        int32_t mean =0;
        //センサのノイズを打ち消すため、複数回の距離センサを作動させ、その平均値を取る
        for (int i = 0; i < MEAN_SIZE; ++i) {
            mean += front_sensor;
        }
        mean = mean / MEAN_SIZE;

        return mean >= WALL_TH;
    }


/* 左センサが閾値を超えているかで、壁の設置の有無を返す */
    inline bool is_opened_right_wall() {
        int32_t mean = 0;
        //センサのノイズを打ち消すため、複数回の距離センサを作動させ、その平均値を取る
        for (int i = 0; i < MEAN_SIZE; ++i) {
            mean += right_sensor;

        }
        mean = mean / MEAN_SIZE;

        return mean >= WALL_TH;
    }


/* 中央センサの壁検知距離を返す */
    inline int get_front_wall_distance() {
        return front_sensor;
    }


/* 左センサの壁検知距離を返す */
    inline int get_left_wall_distance() {
        return left_sensor;
    }


/* 右センサの壁検知距離を返す */
    inline int get_right_wall_distance() {
        return right_sensor;
    }

};


#endif //NEWZUZUMOUSE_SENSORMANAGER_H
