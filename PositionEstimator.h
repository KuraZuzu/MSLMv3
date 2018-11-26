//
// Created by 倉澤　一詩 on 2018/11/24.
//

#ifndef NEWZUZUMOUSE_POSITIONESTIMATER_H
#define NEWZUZUMOUSE_POSITIONESTIMATER_H

//#include "Motor.h"
#include "Point.h"

class PositionEstimator {

private:


    Position& _odometry;

    Position _world_position;

public:

    PositionEstimator(Position& odometry);
    Position get_position(){ return _odometry;}
    MapPosition get_map_position();

    void set_position(double_t x, double_t y, double_t rad);


//
//    Position get_current_x_mm (float_t odometry_x){
//
////        odometry_x = motor.get_moved_x();
//
//        return odometry_x;
//    };
//
//
//    float_t get_current_y_mm (float_t odometry_y){
//
//        odometry_y = motor.get_moved_y();
//
//        return odometry_y;
//    };
//
//
//
//    int get_current_x_block (float_t odometry_x){
//
//        odometry_x = motor.get_moved_x();
//
//        return (int) odometry_x / 180;
//    };
//
//    int get_current_y_block (float_t odometry_y){
//
//        odometry_y = motor.get_moved_y();
//
//        return (int) odometry_y / 180;
//    };
//
//
//    int get_rad (float_t odometry_rad){
//
//        odometry_rad = motor.get_moved_rad();
//
//        if (motor.get_moved_rad() < -2 * 3.14159265){
//             odometry_rad = -2 * 3.14159265
//        }
//
//        return
//    };

};


#endif //NEWZUZUMOUSE_POSITIONESTIMATER_H
