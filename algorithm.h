//
// Created by yamany on 2018/11/25.
//

#ifndef MSLMV3_ALGORITHM_H
#define MSLMV3_ALGORITHM_H

#include "Map3.h"

void saitan(Map3 &map){
    int tmp_cnt = 0;
    Point<uint8_t > v_point;
    v_point = map.size();
    Map3 walk_map(v_point.x,v_point.y);
    Block tmp_block;
    walk_map = map;

    while (v_point.x < 0 && v_point.y < 0) {
        for(uint8_t i=1; i<map.size().x; i++){
            for(uint8_t j=1; j<map.size().y; j++){
                v_point.x=i;
                v_point.y=j;
                tmp_block = map.at(v_point);

                if(walk_map.at(v_point).get_walk_cnt()==255)
                    continue;
                if(j < v_point.y-1){
                    if((tmp_block.get_wall() & NORTH_MASK) != NORTH_MASK){
                        tmp_cnt = tmp_block.get_walk_cnt();
                        v_point.y++;
                        tmp_block = map.at(v_point);
                        if(tmp_block.get_walk_cnt() == 255){
                            tmp_block.set_walk_cnt(tmp_cnt+1);
                            walk_map.set_block(tmp_block, v_point);
                        }
                    }
                }
                if(i < v_point.x-1){
                    if((tmp_block.get_wall() & EAST_MASK) != EAST_MASK){
                        tmp_cnt = tmp_block.get_walk_cnt();
                        v_point.x++;
                        tmp_block = map.at(v_point);
                        if(tmp_block.get_walk_cnt() == 255){
                            tmp_block.set_walk_cnt(tmp_cnt+1);
                            walk_map.set_block(tmp_block, v_point);
                        }
                    }
                }
                if(j>1){
                    if((tmp_block.get_wall() & SOUTH_MASK) != SOUTH_MASK){
                        tmp_cnt = tmp_block.get_walk_cnt();
                        v_point.y--;
                        tmp_block = map.at(v_point);
                        if(tmp_block.get_walk_cnt() == 255){
                            tmp_block.set_walk_cnt(tmp_cnt+1);
                            walk_map.set_block(tmp_block, v_point);
                        }
                    }
                }
                if(i>1){
                    if((tmp_block.get_wall() & WEST_MASK) != WEST_MASK){
                        tmp_cnt = tmp_block.get_walk_cnt();
                        v_point.x--;
                        tmp_block = map.at(v_point);
                        if(tmp_block.get_walk_cnt() == 255){
                            tmp_block.set_walk_cnt(tmp_cnt+1);
                            walk_map.set_block(tmp_block, v_point);
                        }
                    }
                }
            }
        }

    }


}


#endif //MSLMV3_ALGORITHM_H
