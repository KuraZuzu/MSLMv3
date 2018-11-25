//
// Created by 倉澤　一詩 on 2018/11/16.
//

#ifndef NEWZUZUMOUSE_POINT_H
#define NEWZUZUMOUSE_POINT_H

#include <cmath>
#include <inttypes.h>

template <typename T>
struct Point{

public:

    T x;
    T y;


};


struct Position : public Point<double_t>{


public:
    double_t rad;

};

struct MapPosition : public Point<uint8_t>{

public:
    uint8_t direction;

};


#endif //NEWZUZUMOUSE_POINT_H
