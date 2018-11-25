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

    ~Map3();

    void set_block(Block block, Point<uint8_t> point){
        _block[point.x][point.y] = block;
        if(((block.get_block_info()&NORTH_MASK) == NORTH_MASK) && (point.y < _y_size-1)) {
            _block[point.x][point.y + 1].set_south_wall();
        }
        if(((block.get_block_info()&WEST_MASK) == WEST_MASK) && (0 < point.x)) {
            _block[point.x - 1][point.y].set_east_wall();
        }
        if(((block.get_block_info()&EAST_MASK) == EAST_MASK) && (point.x < _x_size-1)) {
            _block[point.x + 1][point.y].set_west_wall();
        }

    }

    Block get_block(Point<uint8_t> point){
        return _block[point.x][point.y];
    }

protected:
    Block **_block;
    uint8_t _x_size = 0;
    uint8_t _y_size = 0;
    Point <uint8_t>_point;

    void map_init();

};


#endif //NEWZUZUMOUSE_MAP_3_H
