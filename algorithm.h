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
    v_point = map.size();
    Map3 walk_map = walk_map;
    Block tmp_block;
    bool change_flg=false;

    do {
        change_flg = false;
        for(uint8_t i=1; i<map.size().x-1; i++){
            for(uint8_t j=1; j<map.size().y-1; j++){
                v_point.x=i;
                v_point.y=j;
                tmp_block = map.at(v_point);

                if(walk_map.at(v_point).walk_cnt==255)
                    continue;
                if(j < v_point.y-1){
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
                }
                if(i < v_point.x-1){
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
                }
                if(j>1){
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
                }
                if(i>1){
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
        }

    }while(change_flg == true);


}


#endif //MSLMV3_ALGORITHM_H
