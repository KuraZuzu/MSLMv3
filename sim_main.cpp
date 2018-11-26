//
// Created by yamany on 2018/11/25.
//
#include <iostream>
#include "map3.h"
#include "map_mbed.h"
#include "vector.h"

using namespace std;

int main(){
    Vector <int> v;
    Vector <double> vv;

    v.push_back(5);
    vv.push_back(4.3);
    v.push_back(4);
    vv.push_back(2.3);
    v.push_back(0);
    vv.push_back(4.1);
    for (int i=0; i<v.size() ; i++){
        cout << v.at(i) << ":" << vv.at(i) << endl;
    }

//    int x = 16, y = 16;
//    Map_Mbed map(16,16);
//    Point <uint8_t>p;
//    Block b;
//
//    for (int i = 0; i < x; ++i) {
//        for (int j = 0; j < y; ++j) {
//            p.x = i;
//            p.y = j;
//            map.set_block(b, p);
//        }
//    }
//    b.set_north_wall();
//    b.set_east_wall();
//    b.set_west_wall();
//    b.set_south_wall();
//    p.x = 13;
//    p.y = 4;
//    map.set_block(b, p);
//    map.write_map();
//    return 0;
}