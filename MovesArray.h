#ifndef MovesArray
#define MovesArray
#include <stdio.h>
#include <stdlib.h>
#include "Types.h"

void PrintMovesBoard(movesArray** moves);
void PrintBoard(char** board);
void initMovesArray(movesArray** moves);
boardPosArray** validMoves(movesArray** moves, char** board);
int isValid(char** board, Move cellDest, int i, int j);
#endif
