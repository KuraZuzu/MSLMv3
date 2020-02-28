//
// Created by 山西
//

#ifndef MSLMV3_MAP_MBED_H
#define MSLMV3_MAP_MBED_H

#include "map3.h"
#include "fstream"

class Map_Mbed : public Map3 {
public:
    using Map3::Map3;
    void write_map();
};


#endif //MSLMV3_MAP_MBED_H
