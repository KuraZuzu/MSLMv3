//
// Created by yamany on 2018/11/25.
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
        outputfile<<"|";
        for (uint8_t j = 0; j < _x_size; ++j) {
            _point.x=j;
            _point.y=_y_size -(uint8_t)1 -i;
            tmp = at(_point).walk_cnt;
            if(99<tmp && tmp<256) outputfile<<tmp;
            else if(9<tmp && tmp<100) outputfile<<" "<<tmp;
            else if(-1<tmp && tmp<10) outputfile<<" "<<tmp<<" ";
            else outputfile << "err";
            a = at(_point).get_wall();
            if(((a&EAST_MASK) == EAST_MASK) || (j == _x_size-1)) outputfile<<"|";
            else outputfile << " ";
        }

        outputfile<<std::endl;
        outputfile<<"+";
        for (uint8_t j = 0; j < _x_size; ++j) {
            _point.x=j;
            _point.y=_y_size-(uint8_t)1-i;
            a = at(_point).get_wall();
            if(((a&SOUTH_MASK) == SOUTH_MASK) || (i == _y_size-1)) outputfile<<"---";
            else outputfile<<"   ";
            outputfile<<"+";
        }
        outputfile<<std::endl;
    }
    outputfile.close();
    /*int i, j;
    uint8_t a = 0;
    FILE *fp;
    LocalFileSystem *local;
    local = new LocalFileSystem("local");

    fp = fopen("/local/TEST.TXT" ,"w");

    for(i = 0; i < _x_size; i++){
        for(j = 0; j < _y_size; j++){
            a = _block[i][j].get_wall();
            fprintf(fp, "%d ",(int)_point.x);
            fprintf(fp, "%d ",(int)_point.y);
            fprintf(fp, "%d ", (int)a);
        }
    }
    fclose(fp);

    delete local;
     */

}
