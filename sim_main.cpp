//
// Created by yamany on 2018/11/25.
//
#include <iostream>
#include "map3.h"
#include "map_mbed.h"
#include "vector.h"
#include "algorithm.h"


using namespace std;

int main(){
    int x = 16, y = 16;
    Map_Mbed map(16,16);
    Point <uint8_t> p;
    Block b;
    b.set_wall(SOUTH_MASK);

    for (int i = 1; i < x-1; ++i) {
        for (int j = 1; j < y; ++j) {
            p.x = i;
            p.y = j;
            map.set_block(b, p);
        }
    }

    //以下walkmap生成

    int tmp_cnt = 0;
    Point<uint8_t > v_point, c_point;
    Block tmp_block;
    bool change_flg=false;
    c_point.x=(uint8_t)7;
    c_point.y=(uint8_t)7;
    map.set_walk_cnt(c_point, 0);
    do {
        change_flg = false;
        for(uint8_t i=0; i<map.size().x; i++){
            for(uint8_t j=0; j<map.size().y; j++){
                v_point.x=i;
                v_point.y=j;
                tmp_block = map.at(v_point);
                tmp_cnt = tmp_block.walk_cnt;
                if(map.at(v_point).walk_cnt==255) continue;

                if(j<map.size().y-1 && ((tmp_block.get_wall() & NORTH_MASK) != NORTH_MASK)){
                    v_point.y++;
                    tmp_block = map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        map.set_walk_cnt(v_point, tmp_cnt+1);
                        change_flg = true;
                    }
                    v_point.y--;
                }
                if(i<map.size().x-1 &&((tmp_block.get_wall() & EAST_MASK) != EAST_MASK)){
                    v_point.x++;
                    tmp_block = map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        map.set_walk_cnt(v_point, tmp_cnt+1);
                        change_flg = true;
                    }
                    v_point.x--;
                }
                if(0<j&&((tmp_block.get_wall() & SOUTH_MASK) != SOUTH_MASK)){
                    v_point.y--;
                    tmp_block = map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        map.set_walk_cnt(v_point, tmp_cnt+1);
                        change_flg = true;
                    }
                    v_point.y++;
                }
                if(0<i&&((tmp_block.get_wall() & WEST_MASK) != WEST_MASK)){
                    v_point.x--;
                    tmp_block = map.at(v_point);
                    if(tmp_block.walk_cnt == 255){
                        map.set_walk_cnt(v_point, tmp_cnt+1);
                        change_flg = true;
                    }
                    v_point.x++;
                }
            }
        }

    }while(change_flg);




    map.write_map();


    return 0;
}