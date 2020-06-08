//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "BinFile.h"


void saveListToBinFile(char* file_name, boardPosArray* pos_arr){
    unsigned int j = 0;
    BYTE c[3] = {0,0,0};
    unsigned int lenName = strlen(file_name) + 5;
    char* file = (char*)malloc(sizeof(char) * lenName);
    sprintf(file, "%s%s", file_name, ".bin");
    FILE* fb;
    fb = fopen(file, "wb");
    free(file);

        fwrite(&pos_arr->size, sizeof(short), 1, fb);
        int index = pos_arr->size;
        while (j < pos_arr->size) {
            if (index / 4 == 0 && ((j % 4 == 1) || (j % 4 == 2) )) {
                if (j % 4 == 1) {
                    c[0] = (pos_arr->positions[j][0] - 'A') << 5) | (pos_arr->positions[j][1] - '1' << 2);
                    fwrite(&c, sizeof(BYTE), 1, fb);
                }else {
                    c[0] = (pos_arr->positions[j][0] - 'A') << 5) | (pos_arr->positions[j][1] - '1' << 2) | (pos_arr->positions[j + 1][0] - 'A' >> 1);
                    c[1] = (pos_arr->positions[j + 1][0] - 'A' << 7) | (pos_arr->positions[j + 1][1] - '1' << 4);
                    fwrite(&c, sizeof(BYTE), 2, fb);
                }
                j += pos_arr->size;
            }
            else {
                setBits(pos_arr,c,&j);
                for (int k = 0; k < 3; k++){
                    fwrite(&c[k], sizeof(BYTE), 1, fb);
                }
                fwrite(&c, sizeof(BYTE), 3, fb);
                index -= 4;
                j += 4;
            }
    }

    fclose(fb);
}

void setBits(boardPosArray* pos_arr,BYTE res[], int j) {
    res[0]= (pos_arr->positions[j][0] - 'A') << 5) | (pos_arr->positions[j][1] - '1' << 2) | (pos_arr->positions[j+1][0] - 'A' >>1);
    res[1] = (pos_arr->positions[j + 1][0] - 'A' << 7) | (pos_arr->positions[j + 1][1] - '1' << 4 ) | (pos_arr->positions[j + 2][0] - 'A' << 1) | (pos_arr->positions[j + 2][1] - '1' >> 2);
    res[2]= (pos_arr->positions[j + 2][1] - '1' << 6) | (pos_arr->positions[j + 3][0] - 'A' << 3) | (pos_arr->positions[j + 3][1] - '1' );
}