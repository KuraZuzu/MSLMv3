//
// Created by yamany on 2018/11/25.
//

#ifndef MSLMV3_ALGORITHM_H
#define MSLMV3_ALGORITHM_H

#include "Map3.h"

void saitan(Map3 &map){
    int walk_cnt = 0;
    Map3 walk_map(16,16);
    Point<uint8_t > v_point;
    Block tmp_block;
    walk_map = map;

    v_point.x = 0;
    v_point.y = 0;
    tmp_block = map.at(v_point);

    walk_cnt++;


}

#endif //MSLMV3_ALGORITHM_H
