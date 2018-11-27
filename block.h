//
// Created by 倉澤　一詩 on 2018/11/11.
//

#ifndef NEWZUZUMOUSE_BLOCK_H
#define NEWZUZUMOUSE_BLOCK_H


#include <cstdint>
#include "deftype.h"

class Block {

private:
                  //         NESW <- mask (North, East, South, West)//
    uint8_t _b;
    int walk_cnt;

public:
    Block();

    void set_wall(uint8_t b);
    void reset_wall();

    bool is_opened_wall(uint8_t t);

    uint8_t get_wall();
    void set_searched();
    bool is_searched();
    int get_walk_cnt();

    void set_walk_cnt(int walk_num);
};


#endif //NEWZUZUMOUSE_BLOCK_H
