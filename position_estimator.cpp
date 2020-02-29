//
// Created by 倉澤　一詩 on 2018/11/24.
//

#include "position_estimator.h"
#include "deftype.h"

PositionEstimator::PositionEstimator(Position& odometry, SensorManager& sensor) : _odometry(odometry), _sensor(sensor){


}

Position PositionEstimator::get_position(){
    return _odometry;
}

void PositionEstimator::set_position(double_t x, double_t y, double_t rad) {
    _odometry.x = x;
    _odometry.y = y;
    _odometry.rad = rad;
}

MapPosition PositionEstimator::get_map_position() {
    MapPosition v;
    v.x = _odometry.x / 180.0;
    v.y = _odometry.y / 180.0;

    const double_t  current_x = sin(_odometry.rad);
    const double_t  current_y = cos(_odometry.rad);

    const double_t r_x = (current_x * cos(PI/4)) - (current_y * sin(PI/4));
    const double_t r_y = (current_x * sin(PI/4)) + (current_y * cos(PI/4));

    if ((0. < r_x) && (0. < r_y)) {

        v.direction = WEST_MASK;

    } else if ((0. < r_x) && (r_y < 0.)) {

        v.direction = SOUTH_MASK;

    } else if ((r_x < 0.) && (r_y < 0.)) {

        v.direction = EAST_MASK;

    } else {

        v.direction = NORTH_MASK;

    }

    return v;
}


/* 各方向ごとに、壁があれば壁情報設置として更新 */
void PositionEstimator::update_map(Map3& _map){
    MapPosition pos = get_map_position();
    Block b;
    uint8_t wall = 0;
    switch (pos.direction){  //機体の向いてる方向に対して分岐

        case NORTH_MASK: // 北方向を向いてる時
            wall |= (!_sensor.is_opened_left_wall())? WEST_MASK:0;
            wall |= (!_sensor.is_opened_front_wall())? NORTH_MASK:0;
            wall |= (!_sensor.is_opened_right_wall())? EAST_MASK:0;
            break;

        case EAST_MASK:  // 東方向を向いてる時
            wall |= (!_sensor.is_opened_left_wall())? NORTH_MASK:0;
            wall |= (!_sensor.is_opened_front_wall())? EAST_MASK:0;
            wall |= (!_sensor.is_opened_right_wall())? SOUTH_MASK:0;
            break;

        case SOUTH_MASK: // 南方向を向いてる時
            wall |= (!_sensor.is_opened_left_wall())? EAST_MASK:0;
            wall |= (!_sensor.is_opened_front_wall())? SOUTH_MASK:0;
            wall |= (!_sensor.is_opened_right_wall())? WEST_MASK:0;
            break;

        case WEST_MASK:  // 西方向を向いてる時
            wall |= (!_sensor.is_opened_left_wall())? SOUTH_MASK:0;
            wall |= (!_sensor.is_opened_front_wall())? WEST_MASK:0;
            wall |= (!_sensor.is_opened_right_wall())? NORTH_MASK:0;
            break;
    }

    b.set_wall(wall); //壁情報をセットする
    _map.set_block(b, pos);
}
