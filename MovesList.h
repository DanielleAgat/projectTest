//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2:

#ifndef PROJECT_MOVESLIST_H
#define PROJECT_MOVESLIST_H
#include "Types.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

//TODO: Add description
int display( movesList* moves_list, boardPos start, char** board);

//TODO: Add description
void copyBoard(char** orig, char dest[][M]);

//TODO: Add description
bool moveCellIfValid(char board[][M],boardPos currCell, Move move);

//TODO: Add description
void removeMoveFromList(movesList* moves_List,moveCell* toRemove);

//Free memory allocation functions:

//TODO: Add description
void freeMovesList(movesList* moves_list);

//TODO: Add description
void _freeMovesList(moveCell* move);

//TODO: Add description
void freeMoveCell(moveCell* moveNode);

#endif
