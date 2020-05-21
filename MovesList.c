//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2:

#include "MovesList.h"

int display(movesList* moves_list, boardPos start, char** board){
    char boardCopy[N][M];
    int counter = 0;
    moveCell* currMoveCell = moves_list->head;
    copyBoard(board,boardCopy);

    while(currMoveCell != NULL){
        if(!moveCellIfValid(boardCopy,start,currMoveCell->move)){
            removeMoveFromList(moves_list, currMoveCell);
            counter++;
        }
        currMoveCell = currMoveCell->next;
    }

//    TODO: Print the copy board
    return counter;
}

void copyBoard(char** orig, char dest[][M]){
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            dest[i][j] = orig[i][j];
}

bool moveCellIfValid(char board[][M],boardPos currCell, Move move){
    bool isValid = false;

    char verticalStep = changeInCapitals(move.rows); //TODO: Check the (-) issue
    char horizontalStep = move.cols; //TODO: Check the (-) issue
    if(board[currCell[0] + verticalStep][currCell[1] + horizontalStep] == ' '){
        isValid = true;
        //Update the location of the current cell according to the move:
        board[currCell[0] + verticalStep][currCell[1] + horizontalStep] = '#';
        currCell[0] += verticalStep; //TODO: Check the (-) issue
        currCell[1] += horizontalStep; //TODO: Check the (-) issue
    }
    return isValid;
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