//
// Created by 倉澤　一詩 on 2018/11/24.
//

#include "PositionEstimator.h"
#include "deftype.h"

PositionEstimator::PositionEstimator(Position& odometry, SensorManager& sensor) :_odometry(odometry), _sensor(sensor){


}

void PositionEstimator::set_position(double_t x, double_t y, double_t rad) {
    _odometry.x = x;
    _odometry.y = y;
    _odometry.rad = rad;
}

MapPosition& PositionEstimator::get_map_position() {
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

    return v;
}
