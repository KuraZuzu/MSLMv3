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
    uint8_t _b = 0b00000000;                                   //
public:

    void set_north_wall();
    void set_east_wall();
    void set_south_wall();
    void set_west_wall();
    void reset_wall();

    bool is_opened_north_wall();
    bool is_opened_east_wall();
    bool is_opened_south_wall();
    bool is_opened_west_wall();

    uint8_t get_block_info(){ return _b;}
//////////////とりあえずコンパイル通す為に強引に返り値設定/////
    bool is_searched(){return 1;};
    void set_searched(){};

};


#endif //NEWZUZUMOUSE_BLOCK_H
