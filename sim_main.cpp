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
    Point <uint8_t>p;
    Block b;
    b.set_south_wall();

    p.x=3;
    p.y=3;
    map.set_block(b, p);
    cout << (int)map.at(p).get_block_info()<<", ";
    p.y--;
    b.set_south_wall();
    map.set_block(b, p);
    cout << (int)map.at(p).debug()<<",";
    cout << (int)map.at(p).get_block_info()<<", ";




//    for (int i = 0; i < x; ++i) {
//        for (int j = 0; j < y; ++j) {
//            p.x = i;
//            p.y = j;
//            map.set_block(b, p);
//        }
//    }
//    for (int i = 0; i < x; ++i) {
//        for (int j = 0; j < y; ++j) {
//            cout << (int)map.at(p).get_block_info()<<", ";
//        }
//    }
//    b.set_north_wall();
//    b.set_south_wall();
//    b.set_west_wall();
//    b.set_east_wall();

    p.x=12;
    p.y=5;

    map.set_block(b, p);
    //map.write_map();

    //saitan(map);


    return 0;
}