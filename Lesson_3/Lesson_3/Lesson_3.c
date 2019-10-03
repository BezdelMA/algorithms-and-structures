#include <stdio.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable : 4996)

//Функция заполнения массива псевдослучайными числами
void Input(int* mass, int len)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < len; i++)
	{
		mass[i] = rand() % 100;
	}
}

//Функция обмена переменных значениями
void Swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

//Сортировка пузырьковым способом
void Comparison(int* mass, int len, int* count)
{
	int i, j;
	for (i = len - 1; i >= 0; i--)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (mass[j] > mass[j + 1]) Swap(&mass[j], &mass[j + 1]);
			*count = *count + 1;
		}
	}
}

//Оптимизированный пузырьковый способ
void ComparisonOptimal(int* mass, int len, int* count)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (mass[j] > mass[j + 1]) Swap(&mass[j], &mass[j + 1]);
			*count = *count + 1;
		}
	}
}

//Функция шейкер-сортировки
//Изучал только словестное описание способа сортировки. В код переводил самостоятельно
//Буду рад замечаниям по написанию кода
void Shaker(int* mass, int len, int* count)
{
	int left = 0;
	int right = len - 1;
	int i, j;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (mass[i] > mass[i + 1])
				Swap(&mass[i], &mass[i + 1]);
		}
		for (j = right; j > left; j--)
		{
			if (mass[j] < mass[j - 1])
				Swap(&mass[j], &mass[j - 1]);
		}
		right--;
		left++;
		*count = *count + 1;
	}
}

//Функция PigeonHole Sort - в Интернете прочитал словестное (не код) описание метода.
//Писал сам, не подглядывая, прошу прокомментировать правильность, если не затруднит
void PigeonHole(int* mass, int len, int* count)
{
	int temp[100][2] = { 0 };
	int i, k, j = 0;
	for (i = 0; i < 100; i++)
	{
		temp[i][0] = i;
		*count = *count + 1;
	}
	for (i = 0; i < len; i++)
	{
		temp[mass[i]][1] += 1;
		*count = *count + 1;
	}
	for (i = 0; i < 100; i++)
	{
		if (temp[i][1] != 0)
		{
			for (k = 0; k < temp[i][1]; k++)
			{
				mass[j] = temp[i][0];
				j++;
				*count = *count + 1;
			}
		}
	}
}

//Функция копирования исходного массива
void Enter(int* mass, int len, int* temp)
{
	int i;
	for (i = 0; i < len; i++)
		temp[i] = mass[i];
}

//Вывод на экран массива
void Write(int* mass, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", mass[i]);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Заполнение исходного массива
	int count = 0;
	int len = 30;
	int* mass[30] = { 0 };
	Input(&mass, len);
	printf("Исходный массив: ");
	Write(mass, len);
	printf("\n\n");
	
	//Сортировка пузырьковым способом
	int* massComparison[30];
	Enter(mass, len, &massComparison);
	Comparison(&massComparison, len, &count);
	printf("Отсортированный массив: ");
	Write(massComparison, len);
	printf("\nКоличество операций при выполнении неоптимизированной сортировки: %d", count);
	printf("\n\n");
	
	//Сортировка оптимизированным пузырьковым способом
	count = 0;
	int* optimal[30];
	Enter(mass, len, &optimal);
	ComparisonOptimal(&optimal, len, &count);
	printf("Отсортированный массив: ");
	Write(&optimal, len);
	printf("\nКоличество операций при выполнении ОПТИМИЗИРОВАННОЙ сортировки: %d", count);
	printf("\n\n");

	//Шейкер-сортировка
	count = 0;
	int* massShaker[30];
	Enter(mass, len, massShaker);
	Shaker(&massShaker, len, &count);
	printf("Отсортированный массив: ");
	Write(&massShaker, len);
	printf("\nКоличество операций при выполнении шейкер - сортировки: %d", count);
	printf("\n\n");

	//PigeonHole Sort
	count = 0;
	int* massHole[30];
	Enter(mass, len, massHole);
	PigeonHole(&massHole, len, &count);
	printf("Отсортированный массив: ");
	Write(&massHole, len);
	printf("\nКоличество операций при выполнении PigeonHole Sort (включая создание временного массива): %d", count);
	printf("\n\n");
	return 1;
}