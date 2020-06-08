//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_BINFILE_H
#define PROJECT_BINFILE_H

#include "MovesList.h"
#include "MovesArray.h"
#include "stdio.h"
#include "stdlib.h"
#include "ErrorsHandlings.h"
#include "string.h"

typedef unsigned char BYTE;

//TODO
void saveListToBinFile(char* file_name, boardPosArray* pos_arr);

//TODO
void setBits(boardPosArray* pos_arr,BYTE res[], int j) ;

#endif //PROJECT_BINFILE_H
