//
// Created by yamany on 2018/11/25.
//
#include <iostream>
#include "map3.h"
#include "map_mbed.h"

using namespace std;

int main(){
    int x = 16, y = 16;
    Map_Mbed map(16,16);
    Point <uint8_t>p;
    Block b;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            p.x = i;
            p.y = j;
            map.set_block(b, p);
        }
    }
    b.set_north_wall();
    b.set_east_wall();
    b.set_west_wall();
    b.set_south_wall();
    p.x = 13;
    p.y = 4;
    map.set_block(b, p);
    map.write_map();
    return 0;
}