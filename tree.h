//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#ifndef PROJECT_TREE_H
#define PROJECT_TREE_H

#include "MovesList.h"
#include "MovesArray.h"
#include "stdio.h"
#include "stdlib.h"
#include "ErrorsHandlings.h"

pathTree findAllPossiblePaths ( boardPos start, movesArray **moves, char **board);
treeNode* _findAllPossiblePaths(char** board,movesArray** moves,boardPos start,treeNode* node);
BOOL isEmpty(treeNodeListCell* nextPossiblePos);


#endif
