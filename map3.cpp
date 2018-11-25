//
// Created by 倉澤　一詩 on 2018/11/11.


#include "map3.h"

Map3::Map3(uint8_t x_size, uint8_t y_size) {

    _x_size = x_size;
    _y_size = y_size;
    _block = new Block* [x_size];

    for (int i = 0; i < x_size; ++i) {
        _block[i] = new Block[y_size];    // for(i < x_size)  で  _block[i] = new Block[y_size] では？
    }

    map_init();

}

Map3::~Map3() {

    for (int i = 0; i < _y_size; ++i) {
        delete _block[i];
    }
    delete [] _block;
}


void Map3::map_init() {
    for(int i = 0; i < _x_size; i++){
        _block[_x_size-1][i].set_west_wall();
        _block[0][i].set_east_wall();
    }

    for(int i = 0; i < _y_size; i++){
        _block[i][0].set_south_wall();
        _block[i][_y_size-1].set_north_wall();
    }
}

void Map3::set_block(Block block, Point<uint8_t> point) {
    _block[point.x][point.y] = block;
    _block[point.x][point.y].set_searched();
    if(((block.get_block_info()&NORTH_MASK) == NORTH_MASK) && (point.y < _y_size-1)) {
        _block[point.x][point.y + 1].set_south_wall();
    }
    if(((block.get_block_info()&WEST_MASK) == WEST_MASK) && (0 < point.x)) {
        _block[point.x - 1][point.y].set_east_wall();
    }
    if(((block.get_block_info()&EAST_MASK) == EAST_MASK) && (point.x < _x_size-1)) {
        _block[point.x + 1][point.y].set_west_wall();
    }

}

Block Map3::get_block(Point<uint8_t> point) {
    return _block[point.x][point.y];
}


