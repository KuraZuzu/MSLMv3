//
// Created by yamany on 2018/11/25.
//

#ifndef MSLMV3_MAP_MBED_H
#define MSLMV3_MAP_MBED_H

#include "mbed.h"
#include "map3.h"
//#include "fstream"
LocalFileSystem local("local");

class Map_Mbed : public Map3 {
public:
    using Map3::Map3;
    void write_map();
};


#endif //MSLMV3_MAP_MBED_H
