//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "MovesArray.h"
#include "MovesList.h"
#include "List_Tests.h"
#include "Types.h"
#include "tree.h"

void printTree(pathTree tree);
void printTreeAux(treeNode* node);

//#define question1
//#define question2
#define question3
//#define question3b


int main(){

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

#endif question2

///////////////    Question 3 tests:    ///////////////
#ifdef question3
    movesArray** moves3;
    pathTree tree;
    boardPos start;
    boardPosArray** positionsArray3;
    int i, j;
    moves3 = (movesArray**)malloc(sizeof(movesArray*) * N);
    for (i = 0; i < N; i++){
        moves3[i] = (movesArray*)malloc(sizeof(movesArray) * M);
    }

    start[0] = 'C';
    start[1] = 3;

    initMovesArray(moves3);
//    positionsArray3 = validMoves(moves3,board);
//    PrintMovesBoard(moves3);

//    for (i = 0; i < N; i++){
//        for (j = 0; j < M; j++){
//            int indexPos = 0;
//            while (indexPos < positionsArray3[i][j].size){
//                printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray3[i][j].positions[indexPos][0], positionsArray3[i][j].positions[indexPos][1]);
//                printf("\n");
//                indexPos++;
//            }
//        }
//    }

    tree = findAllPossiblePaths(start,moves3,board);


#endif question3

#ifdef question3b

    char boardQuestion3[M][N] = { {' ',' ', '*', ' '},{'*',' ', ' ', ' '},{ ' ','*', ' ', ' ' },{ ' ',' ', ' ', ' ' } };

	// Test for question #1 // - passed

	int i, j, k;
	movesArray** boardMoves;
	movesArray* currBoardMove;
	boardPosArray** boardPosArr;

	int size;

	boardMoves = (movesArray**)malloc(M * sizeof(movesArray*));

	for (i = 0; i < M; i++)
	{
		boardMoves[i] = (movesArray*)malloc(N * sizeof(movesArray));

		for (j = 0; j < N; j++)
		{
			currBoardMove = &(boardMoves[i][j]);
			currBoardMove->size = 4;
			currBoardMove->moves = (Move*)malloc(4 * sizeof(Move));
			currBoardMove->moves[0].rows = 1;
			currBoardMove->moves[0].cols = -1;
			currBoardMove->moves[1].rows = -1;
			currBoardMove->moves[1].cols = 1;
			currBoardMove->moves[2].rows = 1;
			currBoardMove->moves[2].cols = 1;
			//currBoardMove->moves[3].rows = -1;
			//currBoardMove->moves[3].cols = -1;
		}
	}

	boardPosArr = validMoves(boardMoves, board);
	char tempc1, tempc2;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			size = boardPosArr[i][j].size;
			for (k = 0; k < size; k++)
			{
				tempc1 = boardPosArr[i][j].positions[k][0];
				tempc2 = boardPosArr[i][j].positions[k][1];
				printf("%c%d: %c%c   ", i + 65, j + 1, tempc1,tempc2);
				//printf("%c%d: %d   ", i + 65, j + 1, size);

			}
		}
		printf("\n");
	}

	printf("\n");
	char c;
	for (i = 0; i < M; i++)
	{
		c = i + 'A';
		for (j = 0; j < N; j++)
		{
			currBoardMove = &(boardMoves[i][j]);
			printf("%c%d: %d ", c, j + 1, currBoardMove->size);
			printf("\n");
			//for (k = 0; k < currBoardMove->size; k++)
			//{
			//	c = i + 'A';
			//	printf("%c%d: ", c, j + 1);
			//	printf("%d ", currBoardMove->moves[k].rows);
			//	printf("%d", currBoardMove->moves[k].cols);
			//	printf("\n");
			//}
		}
	}
	printf("\n");
#endif

    exit(0);
}


void printTree(pathTree tree)
{
    treeNode* root = tree.head;

    printTreeAux(root);
}

void printTreeAux(treeNode* node)
{
    treeNodeListCell* curr = NULL;
    int i = 1;
    //TreeNodeListCell* head = NULL;

    if (node->next_possible_positions == NULL)
        return;
    else
    {
        printf("%c%c ", node->position[0], node->position[1]);
        //printf("|leveldown|");

        //head = node->next_possible_positions;

        curr = node->next_possible_positions;

        while (curr)
        {

            printTreeAux(curr->node);
            printf("nextBranch->");

            curr = curr->next;

            if (curr == NULL)
                printf("NULL");

            i++;
        }

        printf("\n");
    }

}

