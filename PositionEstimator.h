//
// Created by 倉澤　一詩 on 2018/11/24.
//

#ifndef NEWZUZUMOUSE_POSITIONESTIMATER_H
#define NEWZUZUMOUSE_POSITIONESTIMATER_H

//#include "Motor.h"
#include "Point.h"
#include "SensorManager.h"
#include "map3.h"
#include "block.h"

class PositionEstimator {
private:
    Position& _odometry;
    Position _world_position;
    SensorManager& _sensor;

public:

    PositionEstimator(Position& odometry, SensorManager& sensor);
    Position get_position(){ return _odometry;}
    MapPosition get_map_position();
    void update_map(Map3& _map){
        MapPosition pos = get_map_position();
        Block b;
        uint8_t wall = 0;
        switch (pos.direction){
            case NORTH_MASK:
                wall |= (!_sensor.is_opened_left_wall())? WEST_MASK:0;
                wall |= (!_sensor.is_opened_center_wall())? NORTH_MASK:0;
                wall |= (!_sensor.is_opened_right_wall())? EAST_MASK:0;
                break;

            case EAST_MASK:
                wall |= (!_sensor.is_opened_left_wall())? NORTH_MASK:0;
                wall |= (!_sensor.is_opened_center_wall())? EAST_MASK:0;
                wall |= (!_sensor.is_opened_right_wall())? SOUTH_MASK:0;
                break;

            case SOUTH_MASK:
                wall |= (!_sensor.is_opened_left_wall())? EAST_MASK:0;
                wall |= (!_sensor.is_opened_center_wall())? SOUTH_MASK:0;
                wall |= (!_sensor.is_opened_right_wall())? WEST_MASK:0;
                break;

            case WEST_MASK:
                wall |= (!_sensor.is_opened_left_wall())? SOUTH_MASK:0;
                wall |= (!_sensor.is_opened_center_wall())? WEST_MASK:0;
                wall |= (!_sensor.is_opened_right_wall())? NORTH_MASK:0;
                break;
        }

        b.set_wall(wall);
        _map.set_block(b, pos);
    }

    void set_position(double_t x, double_t y, double_t rad);

};


#endif //NEWZUZUMOUSE_POSITIONESTIMATER_H
