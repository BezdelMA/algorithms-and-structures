#include <stdio.h>
#include <Windows.h>
#pragma warning(disable : 4996)

int CountWay(int x, int y, int* wall)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i, j;
	for (i = 0; i < 3; i++)
	{
		if (x == wall[0, i] & y == wall[1, i]) return 0;
	}
	if (x == 0 & y == 0) return 0;
	if (x == 0 || y == 0) return 1;
	else return CountWay(x - 1, y, wall) + CountWay(x, y - 1, wall);
}

int Count(int i, int j, int* wall)
{
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			printf("%d ", CountWay(i, j, wall));
		printf("\n");
	}
}

int main()
{
	int wall_1[3][3] = { 0 };
	printf("Количество шагов, за которое король может преодолеть всю доску: \n\n");
	Count(8, 8, wall_1);

	printf("\nХоды с препятствиями: \n\n");
	int wall[3][3] = { {1,2,3}, {1,2,3} };
	Count(8, 8, wall);

	return 0;
}