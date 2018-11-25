//
// Created by yamany on 2018/11/25.
//
#include <iostream>
#include "map3.h"

using namespace std;

int main(){
    Map3 map(16,16);
    Point p;
    Block b;
    uint8_t t = 0;
    b.set_north_wall();
    b.set_east_wall();
    b.set_west_wall();
    b.set_south_wall();

    for (int i = 0; i < 16; ++i) {
        for(int j = 0; j < 16; ++j){
            p.x = i;
            p.y = j;
            map.set_wall(b);
        }
    }
    for (int i = 0; i < 16; ++i) {
        for(int j = 0; j < 16; ++j){

            b = map.get_block(p);
            t = b.get_block_info();
            cout << t  << endl;
        }
    }


    return 0;
}