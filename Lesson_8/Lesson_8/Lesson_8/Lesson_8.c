#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#pragma warning(disable : 4996)

int arr[20] = { 4,19,8,91,73,7,46,74,84,62,29,41,37,85,49,82,98,85,28,85 };
int arrCounting[20] = { 4,19,8,91,73,7,46,74,84,62,29,41,37,85,49,82,98,85,28,85 };
int arrQuick[20] = { 4,19,8,91,73,7,46,74,84,62,29,41,37,85,49,82,98,85,28,85 };
int arrMerge[20] = { 4,19,8,91,73,7,46,74,84,62,29,41,37,85,49,82,98,85,28,85 };
int size = 20, i;

void PrintArr(int arr[20])
{
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void Swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void CountingSort(int* arr)
{
	int arr_2[20] = { 0 };
	int temp[2][100] = { 0 }, j = 0;
	for (i = 0; i < 100; i++)
	{
		temp[0][i] = i;
	}

	for (i = 0; i < size; i++)
	{
		temp[1][arr[i]] += 1;
	}

	for (i = 0; i < 100; i++)
	{
		if (temp[1][i] != 0)

		{
			while (temp[1][i] != 0)
			{
				arr[j] = temp[0][i];
				j++;
				temp[1][i]--;
			}
		}
	}	
}

void QuickSort(int* arr, int left, int right)
{
	int l_hold = left, r_hold = right;
	int centr = arr[left];
	while (left < right)
	{
		while ((arr[right] >= centr) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			Swap(&arr[left], &arr[right]);
			left++;
		}

		while ((arr[left] <= centr) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			Swap(&arr[right], &arr[left]);
			right--;
		}
	}
	centr = left;
	left = l_hold;
	right = r_hold;
	if (left < centr)
		QuickSort(arr, left, centr - 1);
	if (right > centr)
		QuickSort(arr, centr + 1, right);
}

void MergeSort(int* arr_3)
{
	int centr = size / 2;
	if (size % 2 == 1)
		centr++;
	int* temp = (int*)malloc(size*sizeof(int));
	int step, h = 1;

	while (h < size)
	{
		step = h;
		int i = 0, j = centr, k = 0;
		while (step <= centr)
		{
			while ((i < step) && (j < size) && (j < (centr + step)))
			{
				if (arr_3[i] < arr_3[j])
				{
					temp[k] = arr_3[i];
					k++;
					i++;
				}
				else
				{
					temp[k] = arr_3[j];
					k++;
					j++;
				}
			}
			while (i < step)
			{
				temp[k] = arr_3[i];
				i++;
				k++;
			}
			while ((j < (centr + step)) && (j < size))
			{
				temp[k] = arr_3[j];
				j++;
				k++;
			}
			step = step + h;
		}
		h = h * 2;

		for (i = 0; i < size; i++)
			arr_3[i] = temp[i];
	}

}

int main()
{
	PrintArr(arr);
	printf("\n\n");
	CountingSort(arrCounting);
	PrintArr(arrCounting);
	printf("\n\n");
	QuickSort(arrQuick, 0, size - 1);
	PrintArr(arrQuick);
	printf("\n\n");
	MergeSort(arrMerge);
	PrintArr(arrMerge);
}