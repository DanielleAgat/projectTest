#include "MovesArray.h"
void main()
{
	char* board[] = { "  *  ",
					  "*    ",
					  "    *",
					  "  * *" };
	movesArray** moves;
	boardPosArray** positionsArray;
	int i, j;
	moves = (movesArray**)malloc(sizeof(movesArray*) * N);
	for (i = 0; i < N; i++)
	{
		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);
	}

	initMovesArray(moves);
	PrintBoard(board);
	printf("\n");
	PrintMovesBoard(moves);
	printf("\n");
	positionsArray = validMoves(moves, board);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			int indexPos = 0;
			while (indexPos < positionsArray[i][j].size)
			{
				printf("The position for %c%c is:%c%c\n", i + 'A', j + '1', positionsArray[i][j].positions[indexPos][0], positionsArray[i][j].positions[indexPos][1]);
				printf("\n");
				indexPos++;
			}

		}
	}
}
