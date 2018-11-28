//
// Created by yamany on 2018/11/25.
//

#ifndef MSLMV3_ALGORITHM_H
#define MSLMV3_ALGORITHM_H

#include "iostream"
void saitan(Map_Mbed &map){
    int tmp_cnt = 0;
    Point<uint8_t > v_point, c_point;
    Map_Mbed walk_map = map;
    Block tmp_block;
    bool change_flg=false;
    c_point.x=(uint8_t)7;
    c_point.y=(uint8_t)7;
    //walk_map.set_walk_cnt(c_point, 0);
    do {
        change_flg = false;
        for(uint8_t i=1; i<map.size().x-2; i++){
            for(uint8_t j=1; j<map.size().y-2; j++){
                v_point.x=4;
                v_point.y=5;
                tmp_block = walk_map.at(v_point);
                if(walk_map.at(v_point).walk_cnt==255)
                    //continue;
                if((tmp_block.get_wall() & NORTH_MASK) != NORTH_MASK){
                    tmp_cnt = tmp_block.walk_cnt;
                    v_point.y++;
                    tmp_block = walk_map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        tmp_block.walk_cnt = tmp_cnt-1;
                        change_flg = true;
                    }
                }
                if((tmp_block.get_wall() & EAST_MASK) != EAST_MASK){
                    tmp_cnt = tmp_block.walk_cnt;
                    v_point.x++;
                    tmp_block = walk_map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        tmp_block.walk_cnt = tmp_cnt-1;
                        change_flg = true;
                    }
                }
                if((tmp_block.get_wall() & SOUTH_MASK) != SOUTH_MASK){
                    tmp_cnt = tmp_block.walk_cnt;
                    v_point.y--;
                    tmp_block = walk_map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        tmp_block.walk_cnt = tmp_cnt-1;
                        change_flg = true;
                    }
                }
                if((tmp_block.get_wall() & WEST_MASK) != WEST_MASK){
                    tmp_cnt = tmp_block.walk_cnt;
                    v_point.x--;
                    tmp_block = walk_map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        tmp_block.walk_cnt = tmp_cnt-1;
                        change_flg = true;
                    }
                }
            }
        }

    }while(change_flg);


}


#endif //MSLMV3_ALGORITHM_H
