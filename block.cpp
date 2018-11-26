//
// Created by 倉澤　一詩 on 2018/11/11.
//

#include "block.h"

// open = true 1
// close = false 0


void Block::set_north_wall() {
    _b = _b|NORTH_MASK;
}

void Block::set_east_wall() {
    _b = _b|EAST_MASK;
}

void Block::set_south_wall() {
    _b = _b|SOUTH_MASK;
}

void Block::set_west_wall() {
    _b = _b|WEST_MASK;
}



bool Block::is_opened_north_wall() {
    return (NORTH_MASK & _b)==NORTH_MASK;
}

bool Block::is_opened_east_wall() {
    return (EAST_MASK & _b)==EAST_MASK;
}

bool Block::is_opened_south_wall() {
    return (SOUTH_MASK & _b)==SOUTH_MASK;
}

bool Block::is_opened_west_wall() {
    return (WEST_MASK & _b) == WEST_MASK;
}

void Block::reset_wall() {
    _b = 0b00000000;
}

uint8_t Block::get_block_info() { return _b;}

void Block::set_searched() {
    _b = _b|SEARCH_MASK;
}

bool Block::is_searched() {
    return (_b&SEARCH_MASK)==SEARCH_MASK;
}

Block::Block() {
    _b = 0b00000000;
    walk_cnt = 255;
}

void Block::set_walk_cnt(int walk_num) {
    walk_cnt=walk_num;
}

int Block::get_walk_cnt() {return walk_cnt;}
