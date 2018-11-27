//
// Created by 倉澤　一詩 on 2018/11/11.
//

#ifndef NEWZUZUMOUSE_MAP_3_H
#define NEWZUZUMOUSE_MAP_3_H

#include "block.h"
#include "deftype.h"
#include "Point.h"

class Map3 {
public:
    Map3(uint8_t x_size, uint8_t y_size);

    Map3(const Map3& _m){
        Map3(_m._x_size, _m._y_size);
        for (int i = 0; i < _x_size; ++i) {
            for (int j = 0; j < _y_size; ++j) {
                _block[i][j] = _m._block[i][j];
            }
        }
    }

    ~Map3();

    void set_block(Block block, Point<uint8_t> point);

    Block& at(Point<uint8_t> point);

    Point<uint8_t> size(){
        return Point<uint8_t >(_x_size, _y_size);
    }

protected:
    Block **_block;
    uint8_t _x_size = 0;
    uint8_t _y_size = 0;

    Point <uint8_t>_point;


    void map_init();

};


#endif //NEWZUZUMOUSE_MAP_3_H
