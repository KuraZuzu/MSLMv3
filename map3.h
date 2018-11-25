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

    void set_block(Block block, Point<uint8_t> point);

    Block get_block(Point<uint8_t> point);
    
protected:
    Block **_block;
    uint8_t _x_size = 0;
    uint8_t _y_size = 0;
    Point <uint8_t>_point;

    void map_init();

};


#endif //NEWZUZUMOUSE_MAP_3_H
