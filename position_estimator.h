/*!
* @file position_estimator.h v1.0
* @Copyright © 2018 Kazushi Kurasawa
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/

#ifndef NEWZUZUMOUSE_POSITIONESTIMATER_H
#define NEWZUZUMOUSE_POSITIONESTIMATER_H

#include "motor.h"
#include "point.h"
#include "sensor_manager.h"
#include "map3.h"
#include "block.h"

class PositionEstimator {
private:
    Position& _odometry;
    Position _world_position; //学習をさせたモデルのワールド座標(未実装)
    SensorManager& _sensor;

public:

    PositionEstimator(Position& odometry, SensorManager& sensor);

    /**
     * @fn x,y,rad を連続の値としてdouble型でセットする
     */
    void set_position(double_t x, double_t y, double_t rad);

    /**
     * @fn x,y,rad を連続の値としてdouble型で取得する
     */
    Position get_position();

    /**
     * @fnx,y,rad をブロック単位で取得する
     */
    MapPosition get_map_position(); //マップ上のどこのブロックにいるか

    /**
     * @fn マップ情報をアップデート
     */
    void update_map(Map3& _map);

};


#endif //NEWZUZUMOUSE_POSITIONESTIMATER_H
