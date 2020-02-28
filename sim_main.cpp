//
// Created by 山西
//

#include <iostream>
#include "map3.h"
#include "map_mbed.h"
#include "vector.h"
#include "algorithm.h"


using namespace std;


int main(){
    int x = 16, y = 16;
    Map_Mbed map(16,16);//デバッグするためにMapMbed型になってます
    Point <uint8_t> p;
    Block b;


    //以下walkmap生成

    p.x=0;
    p.y=0;
    b.set_wall(7);
    map.set_block(b, p);
    p.x=0;
    p.y=1;
    b.reset_wall();
    b.set_wall(1);
    map.set_block(b, p);
    saitan(map, 2, 2);
    p.x=0;
    p.y=2;
    b.reset_wall();
    b.set_wall(5);
    map.set_block(b, p);
    saitan(map, 2, 2);
    /*
    p.x=0;
    p.y=3;
    b.reset_wall();
    b.set_wall(9);
    map.set_block(b, p);*/
    p.x=1;
    p.y=2;
    //cout << (int)map.at(p).get_wall();
    saitan(map, 2, 2);

    map.write_map();


    return 0;
}