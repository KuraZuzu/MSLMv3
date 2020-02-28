//
// Created by 倉澤　一詩
//

#ifndef NEWZUZUMOUSE_BLOCK_H
#define NEWZUZUMOUSE_BLOCK_H


#include <cstdint>
#include "deftype.h"

class Block {

private:
                  //         NESW <- mask (North, East, South, West)//
    uint8_t _b;

public:
    Block();

    int walk_cnt;

    void set_wall(uint8_t b);
    void reset_wall();

    bool is_opened_wall(uint8_t t);

    uint8_t get_wall();
    void set_searched();
    bool is_searched();
};


#endif //NEWZUZUMOUSE_BLOCK_H
