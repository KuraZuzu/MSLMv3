//
// Created by yamany on 2018/11/25.
//
#include <iostream>
#include "map3.h"

using namespace std;

int main(){
    int x = 16, y = 16;
    Map3 map(16,16);
    Point <uint8_t>p;
    Block b;
    uint8_t t = 0;
    b.set_north_wall();
    b.set_east_wall();
    b.set_west_wall();
    b.set_south_wall();
    for(int k=0; k<2; k++) {
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                p.x = i;
                p.y = j;
                map.set_block(b, p);
            }
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                p.x = i;
                p.y = j;
                b = map.get_block(p);
                t = b.get_block_info();
                cout << (int) t;
            }
            cout << endl;
        }
        b.reset_wall();
    }



    return 0;
}