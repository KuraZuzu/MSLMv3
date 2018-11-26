//
// Created by yamany on 2018/11/25.
//

#ifndef MSLMV3_ALGORITHM_H
#define MSLMV3_ALGORITHM_H

#include "Map3.h"

void saitan(Map3 &map){
    int walk_cnt = 1;
    Point<uint8_t > v_point;
    v_point = map.size();
    Map3 walk_map(v_point.x,v_point.y);
    Block tmp_block;
    walk_map = map;

    v_point.x = (v_point.x-1)/2;
    v_point.y /= (v_point.y-1)/2;
    tmp_block = map.at(v_point);

    while (v_point.x < 0 && v_point.y < 0) {
        for(uint8_t i=1; i<map.size().x; i++){
            for(uint8_t j=1; j<map.size().y; j++){
                if(walk_map.at(v_point).get_walk_cnt()==255)
                    continue;
                if(j < v_point.y-1){
                    if( ((tmp_block.get_block_info() & NORTH_MASK) == NORTH_MASK)){
                        v_point.x=i;
                        v_point.y=j;
                        tmp_block = map.at(v_point);
                        tmp_block.set_walk_cnt(walk_cnt);

                        if(map->walk_map[i][j+1] == 255){
                            map->walk_map[i][j+1] = map->walk_map[i][j] + 1;
                        }
                    }
                }
                if(i < v_point.x-1){
                    if( (map->real_wall[i][j]&0x04)>>2 == 0){
                        if(map->walk_map[i+1][j] == 255){
                            map->walk_map[i+1][j] = map->walk_map[i][j] + 1;
                        }
                    }
                }
                if(j>1){
                    if( (map->real_wall[i][j]&0x02)>>1 == 0){
                        if(map->walk_map[i][j-1] == 255){
                            map->walk_map[i][j-1] = map->walk_map[i][j] + 1;
                        }
                    }
                }
                if(i>1){
                    if( (map->real_wall[i][j]&0x01) == 0){
                        if(map->walk_map[i-1][j] == 255){
                            map->walk_map[i-1][j] = map->walk_map[i][j] + 1;
                        }
                    }
                }
            }
        }

    }


}
if (!(tmp_block.get_block_info() & NORTH_MASK == NORTH_MASK)) {
v_point.y++;
tmp_block = map.at(v_point);
tmp_block.set_walk_cnt(walk_cnt);
walk_map.set_block(tmp_block, v_point);
}
if (!(tmp_block.get_block_info() & EAST_MASK == EAST_MASK)) {
v_point.x++;
tmp_block = map.at(v_point);
tmp_block.set_walk_cnt(walk_cnt);
walk_map.set_block(tmp_block, v_point);
}
if (!(tmp_block.get_block_info() & SOUTH_MASK == SOUTH_MASK)) {
v_point.y--;
tmp_block = map.at(v_point);
tmp_block.set_walk_cnt(walk_cnt);
walk_map.set_block(tmp_block, v_point);
}
if (!(tmp_block.get_block_info() & WEST_MASK == WEST_MASK)) {
v_point.x--;
tmp_block = map.at(v_point);
tmp_block.set_walk_cnt(walk_cnt);
walk_map.set_block(tmp_block, v_point);
}

#endif //MSLMV3_ALGORITHM_H
