//
// Created by 倉澤　一詩 on 2018/11/11.
//

#include "block.h"

// open = true 1
// close = false 0

void Block::set_wall(uint8_t b) {
    _b |= b;
}

bool Block::is_opened_wall(uint8_t b) {
    return (_b & b);
}

void Block::reset_wall() {
    _b = 0b00000000;
}

uint8_t Block::get_wall() { return _b;}

void Block::set_searched() {
    _b |= SEARCH_MASK;
}

bool Block::is_searched() {
    return (_b&SEARCH_MASK)==SEARCH_MASK;
}

Block::Block() {
    _b = 0b00000000;
    walk_cnt = 255;
}

