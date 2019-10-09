#include <stdio.h>
#include <Windows.h>
#pragma warning(disable : 4996)

const int He = 8;
const int Wi = 8;

int possible[][2] = { {-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1} };

int isPossible(int desk[8][8], int x, int y)
{
	return x >= 0 & x < He & y >= 0 & y < Wi & desk[x][y] == 0;
}

void InitDesk(int desk[8][8])
{
	int i, j;
	for (i = 0; i < He; i++)
		for (j = 0; j < Wi; j++)
			desk[i][j] = 0;
}

void PrintDesk(int desk[8][8])
{
	printf("\n");
	int i, j;
	for (i = 0; i < He; i++)
	{
		for (j = 0; j < Wi; j++)
			printf("%3d ", desk[i][j]);
		printf("\n");
	}
}

int KnightMove(int desk[8][8], int x, int y, int move)
{
	int nextX, nextY, i;
	int maxMove = He * Wi - 1;
	desk[x][y] = move;
	if (move > maxMove)
		return 1;
	for (i = 0; i < 8; i++)
	{
		nextX = x + possible[i][0];
		nextY = y + possible[i][1];
		if (isPossible(desk, nextX, nextY) && KnightMove(desk, nextX, nextY, move + 1))
			return 1;
	}

	desk[x][y] = 0;
	return 0;
}

int CountWay(int x, int y, int* wall[2][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		if (x == wall[0][i] & y == wall[1][i]) return 0;
	}
	if (x == 0 & y == 0) return 0;
	if (x == 0 || y == 0) return 1;
	else return CountWay(x - 1, y, wall) + CountWay(x, y - 1, wall);
}

int Count(int i, int j, int wall[2][3])
{
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			printf("%4d ", CountWay(i, j, wall));
		printf("\n");
	}
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int wall_1[2][3] = { 0 };
	printf("Количество шагов, за которое король может преодолеть всю доску: \n\n");
	Count(8, 8, wall_1);

	printf("\nХоды с препятствиями: \n\n");
	int wall[2][3] = { {5,2,3}, {1,2,3} };
	Count(8, 8, wall);

	int desk[8][8];
	InitDesk(desk);
	KnightMove(desk, 0, 0, 1);
	PrintDesk(desk);
	
	return 0;
}