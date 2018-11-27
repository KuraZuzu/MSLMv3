//
// Created by 倉澤　一詩 on 2018/11/24.
//

#include "PositionEstimator.h"
#include "deftype.h"

PositionEstimator::PositionEstimator(Position& odometry) :_odometry(odometry){}

void PositionEstimator::set_position(double_t x, double_t y, double_t rad) {
    _odometry.x = x;
    _odometry.y = y;
    _odometry.rad = rad;
}

MapPosition PositionEstimator::get_map_position() {
    MapPosition v;
    v.x = _odometry.x / 180.0;
    v.y = _odometry.y / 180.0;

//    int32_t k;

    const double_t  current_x = sin(_odometry.rad);
    const double_t  current_y = cos(_odometry.rad);

    const double_t r_x = (current_x * cos(PI/4)) - (current_y * sin(PI/4));
    const double_t r_y = (current_x * sin(PI/4)) + (current_y * cos(PI/4));

    if ((0 < r_x) && (0 < r_y)) {

//        v.direction = NORTH_MASK;
        v.direction = WEST_MASK;


    } else if ((0 < r_x) && (r_y < 0)) {

//        v.direction = WEST_MASK;
        v.direction = SOUTH_MASK;


    } else if ((r_x < 0) && (r_y < 0)) {

//        v.direction = SOUTH_MASK;
        v.direction = EAST_MASK;


    } else {

//        v.direction = EAST_MASK;
        v.direction = NORTH_MASK;

    }



//    if (0 <= _odometry.rad){
////        k = (int32_t)(_odometry.rad / (2*PI));
////    } else {
////        k = (int32_t)(_odometry.rad / (2*PI));
////    }
////
////    const double_t one_range_rad = _odometry.rad - ((2*PI) * k);
////
////    if ( ((0 < one_range_rad) && (one_range_rad < (2*PI)*(1/4))) || (((2*PI)*(7/4) < one_range_rad) && (one_range_rad < (2*PI)*(8/4))) ) {
////
////        if (0 <= k) v.direction = NORTH_MASK;
////        else v.direction = WEST_MASK;
////
////    } else if (((1/4)*(2*PI) < one_range_rad) && (one_range_rad < (2*PI)*(3/4))) {
////
////        if (0 <= k) v.direction = EAST_MASK;
////        else v.direction = SOUTH_MASK;
////
////    } else if (((3/4)*(2*PI) < one_range_rad) && (one_range_rad < (2*PI)*(5/4))) {
////
////        if (0 <= k) v.direction = SOUTH_MASK;
////        else v.direction = EAST_MASK;
////
////    } else {
////
////        if (0 <= k) v.direction = WEST_MASK;
////        else v.direction = NORTH_MASK;
////
////    }




//    if (0 <= _odometry.rad){
//        k = (int32_t)(_odometry.rad / (2*PI)) + 1;
//    } else {
//        k = (int32_t)(_odometry.rad / (2*PI)) - 1;
//    }
//
//    if ( ( ( 0 < (_odometry.rad / k) / (2*PI) ) && ( ( (_odometry.rad / k) / (2*PI) ) < (1/8) ) ) || ( (7/8) < ( (_odometry.rad / k) / (2*PI) ) && ( (_odometry.rad / k) / (2*PI) ) < (2*PI) ) ) {
//
//        if (0 <= k) v.direction = NORTH_MASK;
//        else v.direction = WEST_MASK;
//
//    } else if ( ( (3/8) < ( (_odometry.rad / k) / (2*PI) ) )  && (5/8) < ( (_odometry.rad / k) / (2*PI) ) ) {
//
//        if (0 <= k) v.direction = EAST_MASK;
//        else v.direction = SOUTH_MASK;
//
//    } else if ( ( ( (_odometry.rad / k) / (2*PI) ) < (5/8) )  && (7/8) < ( (_odometry.rad / k) / (2*PI) ) ) {
//
//        if (0 <= k) v.direction = SOUTH_MASK;
//        else v.direction = EAST_MASK;
//
//    } else {
//
//        if (0 <= k) v.direction = WEST_MASK;
//        else v.direction = NORTH_MASK;
//
//    }

    return v;
}
