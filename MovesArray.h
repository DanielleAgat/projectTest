#ifndef MovesArray
#define MovesArray
#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 5


typedef char boardPos[2];

typedef struct _move { // תזוזה על הלוח 
	char rows, cols;
} Move;

typedef struct _movesArray {  // מערך של תזוזות בלוח 
	unsigned int size;
	Move* moves;
} movesArray;

typedef struct _boardPosArray { //מערך של מיקומי משבצות בלוח    
	unsigned int size;
	boardPos* positions;
} boardPosArray;


void PrintMovesBoard(movesArray** moves);
void PrintBoard(char** board);
void initMovesArray(movesArray** moves);
boardPosArray** validMoves(movesArray** moves, char** board);
int isValid(char** board, Move cellDest, int i, int j);
#endif
