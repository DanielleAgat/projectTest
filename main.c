//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "MovesArray.h"
#include "MovesList.h"
#include "List_Tests.h"

void main(){
//#define question1
#define question2

	char* board[] = { "  *  ",
					  "*    ",
					  "    *",
					  "  * *" };

    char* emptyBoard[] = { "     ",
                           "     ",
                           "     ",
                           "     " };

///////////////    Question 1 tests:    ///////////////
#ifdef question1
	movesArray** moves;
	boardPosArray** positionsArray;
	int i, j;
	moves = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++){
		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	initMovesArray(moves);
	PrintBoard(board);
	printf("\n");
	PrintMovesBoard(moves);
	printf("\n");
	positionsArray = validMoves(moves, board);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			int indexPos = 0;
			while (indexPos < positionsArray[i][j].size){
				printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray[i][j].positions[indexPos][0], positionsArray[i][j].positions[indexPos][1]);
				printf("\n");
				indexPos++;
			}
		}
	}
#endif

///////////////    Question 2 tests:    ///////////////
#ifdef question2
    boardPos start = {'A',2};
    movesList list = getListFromUser();
	printList(list);

	int removedCells = display(&list,start,board);
	printf("Number of invalid moves that were removed: %d",removedCells);

#endif

}



