//
// Created by yamany on 2018/11/25.
//

#include "map_mbed.h"


void Map_Mbed::write_map() {
    uint8_t a = 0;
    int tmp = 255;
    //std::ofstream outputfile("map_data.txt");
    FILE *fp;

    fp = fopen("/local/tset.txt", "w");  // ファイルを書き込みモードで開く
    //outputfile<<"+";
    fprintf(fp, "+");
    for(uint8_t i = 0; i<_x_size; ++i) fprintf(fp, "---+");//outputfile<<"---"<<"+";
    //outputfile<<std::endl;
    fprintf(fp, "\n");
    for (uint8_t i = 0; i < _y_size; ++i) {
        fprintf(fp, "|");//outputfile<<"|";
        for (uint8_t j = 0; j < _x_size; ++j) {
            _point.x=j;
            _point.y=_y_size -(uint8_t)1 -i;
            tmp = at(_point).walk_cnt;
            if(99<tmp && tmp<256) fprintf(fp, "%d", tmp);//outputfile<<tmp;
            else if(9<tmp && tmp<100) fprintf(fp, " %d", tmp);//outputfile<<" "<<tmp;
            else if(-1<tmp && tmp<10) fprintf(fp, " %d ", tmp);//outputfile<<" "<<tmp<<" ";
            else fprintf(fp, "err");//outputfile << "err";
            a = at(_point).get_wall();
            if(((a&EAST_MASK) == EAST_MASK) || (j == _x_size-1)) fprintf(fp, "|");//outputfile<<"|";
            else fprintf(fp, " ");//outputfile << " ";
        }

        fprintf(fp, "\n");//outputfile<<std::endl;
        fprintf(fp, "+");//outputfile<<"+";
        for (uint8_t j = 0; j < _x_size; ++j) {
            _point.x=j;
            _point.y=_y_size-(uint8_t)1-i;
            a = at(_point).get_wall();
            if(((a&SOUTH_MASK) == SOUTH_MASK) || (i == _y_size-1)) fprintf(fp, "---");//outputfile<<"---";
            else fprintf(fp, "   ");//outputfile<<"   ";
            fprintf(fp, "+");//outputfile<<"+";
        }
        fprintf(fp, "\n");//outputfile<<std::endl;
    }
    fclose(fp);//outputfile.close();
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
