//
// Created by 倉澤　一詩 on 2018/11/24.
//

#include "PositionEstimator.h"

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
    return v;
}
