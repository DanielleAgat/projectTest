//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601


#include "PathCalculation.h"

movesList* findPathCoveringAllBoard(boardPos start, movesArray** moves, char** board){
//    TODO: Calculate empty cells in board
    pathTree allPossiblePaths = findAllPossiblePaths(start,moves,board);
//    TODO: Create empty list
//    TODO: Return list of all-cell path

}

BOOL getAllBoardPath(treeNode* root,moveCell* list,int* levelCounter ,int emptyCells){
    if(root == NULL && (*levelCounter != emptyCells)){
        return FALSE;
    }else if(*levelCounter == emptyCells){
        return TRUE;
    }

    if(getAllBoardPath(root->next_possible_positions->node,list,levelCounter+1,emptyCells)){
//        TODO: Add to list
//        TODO: 
    }



}