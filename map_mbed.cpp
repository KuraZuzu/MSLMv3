//
// Created by 山西
//

#include "map_mbed.h"


void Map_Mbed::write_map() {
    uint8_t a = 0;
    int tmp = 255;
    std::ofstream outputfile("map_data.txt");

    outputfile<<"+";
    for(uint8_t i = 0; i<_x_size; ++i) outputfile<<"---"<<"+";
    outputfile<<std::endl;
    for (uint8_t i = 0; i < _y_size; ++i) {
        outputfile << "|";
        for (uint8_t j = 0; j < _x_size; ++j) {
            _point.x = j;
            _point.y = _y_size - (uint8_t) 1 - i;
            tmp = at(_point).walk_cnt;
            if (99 < tmp && tmp < 256) outputfile << tmp;
            else if (9 < tmp && tmp < 100) outputfile << " " << tmp;
            else if (-1 < tmp && tmp < 10) outputfile << " " << tmp << " ";
            else outputfile << "err";
            a = at(_point).get_wall();
            if (((a & EAST_MASK) == EAST_MASK) || (j == _x_size - 1)) outputfile << "|";
            else outputfile << " ";
        }

        outputfile << std::endl;
        outputfile << "+";
        for (uint8_t j = 0; j < _x_size; ++j) {
            _point.x = j;
            _point.y = _y_size - (uint8_t) 1 - i;
            a = at(_point).get_wall();
            if (((a & SOUTH_MASK) == SOUTH_MASK) || (i == _y_size - 1)) outputfile << "---";
            else outputfile << "   ";
            outputfile << "+";
        }
        outputfile << std::endl;
    }
    outputfile.close();

}
