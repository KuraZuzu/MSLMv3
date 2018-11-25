//
// Created by 倉澤　一詩 on 2018/11/11.
//

#ifndef NEWZUZUMOUSE_MAP_3_H
#define NEWZUZUMOUSE_MAP_3_H

#include "block.h"
#include "deftype.h"
#include "Point.h"
#include<fstream>

class Map3 {

private:

    Block **_block;
    uint8_t _x_size = 0;
    uint8_t _y_size = 0;
    Point _point;


    void map_init();

public:

    Map3(uint8_t x_size, uint8_t y_size);

    ~Map3();

    void set_wall(Block _wall_info){
        _block[(int)_point.x][(int)_point.y] = _wall_info;
    }

    void debug_map_info(){

        int i, j;
        u_int8_t a = 0;
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

    }

};


#endif //NEWZUZUMOUSE_MAP_3_H
