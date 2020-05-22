//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2:

#include "MovesList.h"
#include "MovesArray.h"

int display(movesList* moves_list, boardPos start, char** board){
    char** boardCopy = (char**)malloc(sizeof(char*) * N);
    copyBoard(board,boardCopy);
    int counter = 0;
    moveCell* currMoveCell = moves_list->head;

    while(currMoveCell != NULL){
        if(isValid(boardCopy,currMoveCell->move,start[0],start[1])){
            addCellToPath(boardCopy,start,currMoveCell->move);
        }else{
            removeMoveFromList(moves_list, currMoveCell);
            counter++;
        }
        currMoveCell = currMoveCell->next;
    }

    PrintBoard(boardCopy);
    freeBoard(board);
    return counter;
}

void addCellToPath(char** board,boardPos currCell,Move move){
    board[currCell[0] + move.rows][currCell[1] + move.cols] = TAKEN;
    currCell[0] += move.rows + 'A';
    currCell[1] += move.cols + '1';
}

void copyBoard(char** orig, char** dest){
    for(int i = 0 ; i < N ; i++) {
        dest[i] = (char *) malloc(sizeof(char) * M);
        for (int j = 0; j < M; j++)
            dest[i][j] = orig[i][j];
    }
}

void removeMoveFromList(movesList* moves_List, moveCell* toRemove){
    moveCell* temp = toRemove;
    if(toRemove->prev == NULL){
        moves_List->head = toRemove->next;
        moves_List->head->prev = NULL;
    }else if(toRemove->next == NULL){
        moves_List->tail = toRemove->prev;
        moves_List->tail = NULL;
    }else{
        toRemove->prev->next = toRemove->next;
        toRemove->next->prev = toRemove->prev;
    }
    freeMoveCell(temp);
}

void freeMovesList(movesList* moves_list){
    _freeMovesList(moves_list->head);
}

void _freeMovesList(moveCell* moveNode){
    moveCell* temp;
    while(moveNode != NULL){
        temp = moveNode;
        moveNode = moveNode->next;
        freeMoveCell(temp);
    }
}

void freeMoveCell(moveCell* moveNode){
    free(&moveNode->move);
    free(moveNode);
}

void freeBoard(char** board){
    for(int i = 0 ; i < N ; i++)
            free(board[i]);
    free(board);
}