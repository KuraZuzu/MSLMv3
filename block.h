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

    void set_north_wall();
    void set_east_wall();
    void set_south_wall();
    void set_west_wall();
    void reset_wall();

    bool is_opened_north_wall();
    bool is_opened_east_wall();
    bool is_opened_south_wall();
    bool is_opened_west_wall();

    uint8_t get_block_info();
    void set_searched();
    bool is_searched();
    int get_walk_cnt();
    void set_walk_cnt(int walk_num);
    uint8_t debug(){ return _b|NORTH_MASK;}
};


#endif //NEWZUZUMOUSE_BLOCK_H
