//
// Created by yamany on 2018/11/25.
//

#include "map_mbed.h"

void Map_Mbed::write_map() {
    uint8_t a = 0;
    std::ofstream outputfile("map_data.txt");
    outputfile<<"+";
    for(int i = 0; i<_x_size; ++i) outputfile<<"-"<<"+";
    outputfile<<std::endl;
    for (int i = 0; i < _y_size; ++i) {
        outputfile<<"|";
        for (int j = 0; j < _x_size; ++j) {
            outputfile<<"0";
            _point.x=j;
            _point.y=_y_size-1-i;
            a = get_block(_point).get_block_info();
            if((a&0b00000100) == 4 || j == _x_size-1) outputfile<<"|";
            else outputfile<<" ";
        }

        outputfile<<std::endl;
        outputfile<<"+";
        for (int j = 0; j < _x_size; ++j) {
            _point.x=j;
            _point.y=_y_size-1-i;
            a = get_block(_point).get_block_info();
            if((a&0b00000010) == 2 || i == _y_size-1) outputfile<<"-";
            else outputfile<<" ";
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
            a = _block[i][j].get_block_info();
            fprintf(fp, "%d ",(int)_point.x);
            fprintf(fp, "%d ",(int)_point.y);
            fprintf(fp, "%d ", (int)a);
        }
    }
    fclose(fp);

    delete local;
     */

}
