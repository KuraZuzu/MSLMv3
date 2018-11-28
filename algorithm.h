//
// Created by yamany on 2018/11/25.
//

#ifndef MSLMV3_ALGORITHM_H
#define MSLMV3_ALGORITHM_H

#include "Map3.h"
#include "iostream"
void saitan(Map3 &map){
    int tmp_cnt = 0;
    Point<uint8_t > v_point;
    Map3 walk_map = walk_map;
    Block tmp_block;
    bool change_flg=false;
    v_point.x=(v_point.x-1)/2;
    v_point.y=(v_point.y-1)/2;
    tmp_block.walk_cnt=0;
    walk_map.set_block(tmp_block, v_point);
    do {
        change_flg = false;
        for(uint8_t i=0; i<map.size().x-1; i++){
            for(uint8_t j=0; j<map.size().y-1; j++){
                tmp_block = map.at(v_point);
                if(walk_map.at(x,y)==255)
                    continue;
                    if((tmp_block.get_wall() & NORTH_MASK) != NORTH_MASK){
                        tmp_cnt = tmp_block.walk_cnt;
                        v_point.y++;
                        tmp_block = map.at(v_point);
                        if(tmp_block.walk_cnt == 255){
                            tmp_block.walk_cnt = tmp_cnt+1;
                            walk_map.set_block(tmp_block, v_point);
                            change_flg = true;
                        }
                    }
                    if((tmp_block.get_wall() & EAST_MASK) != EAST_MASK){
                        tmp_cnt = tmp_block.walk_cnt;
                        v_point.x++;
                        tmp_block = map.at(v_point);
                        if(tmp_block.walk_cnt == 255){
                            tmp_block.walk_cnt = tmp_cnt+1;
                            walk_map.set_block(tmp_block, v_point);
                            change_flg = true;
                        }
                    }
                    if((tmp_block.get_wall() & SOUTH_MASK) != SOUTH_MASK){
                        tmp_cnt = tmp_block.walk_cnt;
                        v_point.y--;
                        tmp_block = map.at(v_point);
                        if(tmp_block.walk_cnt == 255){
                            tmp_block.walk_cnt = tmp_cnt+1;
                            walk_map.set_block(tmp_block, v_point);
                            change_flg = true;
                        }
                    }
                    if((tmp_block.get_wall() & WEST_MASK) != WEST_MASK){
                        tmp_cnt = tmp_block.walk_cnt;
                        v_point.x--;
                        tmp_block = map.at(v_point);
                        if(tmp_block.walk_cnt == 255){
                            tmp_block.walk_cnt = tmp_cnt+1;
                            walk_map.set_block(tmp_block, v_point);
                            change_flg = true;
                        }
                    }
            }
        }

    }while(change_flg);


}


#endif //MSLMV3_ALGORITHM_H
