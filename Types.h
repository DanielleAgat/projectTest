//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2:

#ifndef PROJECT_TYPES_H
#define PROJECT_TYPES_H

//General types:

//TODO: Add description to MACRO
#define parseInt(char) (char - '0')

//TODO: Add description to MACRO
#define changeInCapitals(char) (char - 'A')

typedef int BOOL;
#define TRUE 1
#define FALSE 0


// Board types:
#define N 4 //Board's rows
#define M 5 //Board's cols

typedef char boardPos[2];

typedef struct _boardPosArray{
    unsigned int size;
    boardPos* positions;
}boardPosArray;


// Move types:
typedef struct _move{
    char rows, cols;
}Move;

typedef struct _movesArray{
    unsigned int size;
    Move* moves;
}movesArray;


typedef struct _moveCell{
    Move move;
    struct _moveCell* next;
    struct _moveCell* prev;
}moveCell;


typedef struct _movesList{
    moveCell* head;
    moveCell* tail;
}movesList;

#endif
