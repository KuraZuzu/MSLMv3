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

    p.x=12;
    p.y=5;

    map.set_block(b, p);

    saitan(map);
    map.write_map();


    return 0;
}