//
// Created by 倉澤　一詩
//

#ifndef NEWZUZUMOUSE_POSITIONESTIMATER_H
#define NEWZUZUMOUSE_POSITIONESTIMATER_H

#include "Motor.h"
#include "Point.h"
#include "SensorManager.h"
#include "map3.h"
#include "block.h"

class PositionEstimator {
private:
    Position& _odometry;
    Position _world_position; //学習をさせたモデルのワールド座標(未実装)
    SensorManager& _sensor;

public:

    PositionEstimator(Position& odometry, SensorManager& sensor);

/* x,y,rad を連続の値としてdouble型でセットする */
    void set_position(double_t x, double_t y, double_t rad);

/* x,y,rad を連続の値としてdouble型で取得する */
    Position get_position();

/* x,y,rad をブロック単位で取得する */
    MapPosition get_map_position(); //マップ上のどこのブロックにいるか

/* マップ情報をアップデート */
    void update_map(Map3& _map);

};


#endif //NEWZUZUMOUSE_POSITIONESTIMATER_H
