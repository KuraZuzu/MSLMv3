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

    for (int i = 1; i < x-1; i+=2) {
        for (int j = 1; j < y; ++j) {
            p.x = i;
            p.y = j;
            map.set_block(b, p);
        }
    }
    b.set_wall(NORTH_MASK);
    b.set_wall(SOUTH_MASK);
    b.set_wall(EAST_MASK);
    b.set_wall(WEST_MASK);
    p.x=2;
    p.y=9;
    map.set_block(b, p);


    //以下walkmap生成

    saitan(map);

    map.write_map();


    return 0;
}