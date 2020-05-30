//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "tree.h"

pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board){
    pathTree path;
    char** boardCopy = (char**)malloc(sizeof(char*) * N);
    copyBoard(board,boardCopy,start);
//    Declaring tree source :
    path.head->position[0] = start[0];
    path.head->position[1] = start[1];
    path.head->next_possible_positions = NULL;
    path.head = _findAllPossiblePaths(boardCopy,moves,start,path.head);
    return path;
}

treeNode* _findAllPossiblePaths(char** board,movesArray** moves,boardPos start,treeNode* node){
    int startCol = start[1];
    int startRow = changeInCapitals(start[0]);
    unsigned int numOfChild = moves[changeInCapitals(start[0])][start[1]].size;

    for(unsigned int i = 0 ; i < numOfChild ; i++ ){ //Runs as long as there are children to the boardpos
        if(isEmpty(node->next_possible_positions)){
//            TODO: Generate empty list - treeNodeListCell
        }
        if(isValid(board,moves[startRow][startCol].moves[i],start[0],start[1])){
//            TODO: Add to end of list - treeNode
            addCellToPath(board,start,moves[startRow][startCol].moves[i],TAKEN);
            _findAllPossiblePaths(board,moves,start,node->next_possible_positions->node);
//            TODO: Check if the board doesn't affect the board on other routes
        }
    }

    return node;
}

BOOL isEmpty(treeNodeListCell* nextPossiblePos){
//    TODO: Fill
}
