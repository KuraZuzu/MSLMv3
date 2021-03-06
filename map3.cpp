/*!
* @file map3.h v1.0
* @Copyright © 2018 Kazushi Kurasawa
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/

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

    _block[0][0].set_wall(EAST_MASK + SOUTH_MASK + WEST_MASK);
    _block[1][0].set_wall(WEST_MASK);

    for(int i = 0; i < _x_size; i++){
        _block[_x_size-1][i].set_wall(EAST_MASK);
        _block[0][i].set_wall(WEST_MASK);
    }

    for(int i = 0; i < _y_size; i++){
        _block[i][0].set_wall(SOUTH_MASK);
        _block[i][_y_size-1].set_wall(NORTH_MASK);
    }
}

void Map3::set_block(Block block, Point<uint8_t> point) {
    _block[point.x][point.y].walk_cnt=block.walk_cnt;
    _block[point.x][point.y].set_searched();
    _block[point.x][point.y].set_wall(block.get_wall());

    if(((block.get_wall()&NORTH_MASK) == NORTH_MASK) && (point.y < _y_size-1)) {
        _block[point.x][point.y + 1].set_wall(SOUTH_MASK);
    }
    if(((block.get_wall()&WEST_MASK) == WEST_MASK) && (0 < point.x)) {
        _block[point.x - 1][point.y].set_wall(EAST_MASK);
    }
    if(((block.get_wall()&EAST_MASK) == EAST_MASK) && (point.x < _x_size-1)) {
        _block[point.x + 1][point.y].set_wall(WEST_MASK);
    }
    if(((block.get_wall()&SOUTH_MASK) == SOUTH_MASK) && (0 < point.y)) {
        _block[point.x][point.y - 1].set_wall(NORTH_MASK);
    }
}

Block& Map3::at(Point<uint8_t> point) {
    return _block[point.x][point.y];
}


