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

    int32_t k;

    if (0 <= _odometry.rad){
        k = (int32_t)(_odometry.rad / (2*PI)) + 1;
    } else {
        k = (int32_t)(_odometry.rad / (2*PI)) - 1;
    }

    if ( (1/4 * k) < (_odometry.rad / (2*PI)) || (3/4 * k) < (_odometry.rad / (2*PI)) ) v.direction = NORTH_MASK;

    else if ( (1/4 * k) < (_odometry.rad / (2*PI)) && (_odometry.rad / (2*PI)) < (3/4 * k) ) v.direction = EAST_MASK;

    else if ( (3/4 * k) < (_odometry.rad / (2*PI)) && (_odometry.rad / (2*PI)) < (5/4 * k) ) v.direction = SOUTH_MASK;

    else v.direction = WEST_MASK;       //( (5/4 * k) < (_odometry.rad / (2*PI)) && (_odometry.rad / (2*PI)) < (7/4 * k) )

    return v;
}
