#include <stdio.h>
#include <Windows.h>
#pragma warning(disable : 4996)

int Input(char* text)
{
	int temp;
	printf("Введите %s", text);
	scanf("%d", &temp);
	return temp;
}

void BinaryConversionRecurs(int digit)
{
	if (digit > 1)
			BinaryConversionRecurs(digit / 2);
	printf("%d", digit % 2);
}

//Перевод из десятичной системы исчисления в двоичную
int BinaryConversion(int digit)
{
	int temp = 0;
	int mass[10] = { 0 };
	int i = 0;
	
	//Высчитываем остатки от деления на 2
	while (digit != 1)
	{
		int residue = digit % 2;
		digit /= 2;
		mass[i] = residue;
		i++;
	}
	if (digit % 2 == 0)
		mass[i] = 0;
	
	else 
		mass[i] = 1;
	
	//Записываем результаты в переменную типа int для передачи в main
	for (i = 9; i >= 0; i--)
		temp = temp * 10 + mass[i];
	return temp;
}

//Возведение в степень с использованием рекурсии
int ExponentiationRecurs(int number, int rank)
{
	if (rank == 0) return 1;
	else return ExponentiationRecurs(number, rank - 1) * number;
}

//Возведение в степень без использования рекурсии (через цикл FOR)
int Exponentiation(int number, int rank)
{
	if (rank == 0) return 1;
	else {
		int temp = number, i;
		for (i = 0; i < rank - 1; i++)
		{
			temp *= number;
		}
		return temp;
	}
}

//Возведение в степень используя свойство четности степени (вызывается только когда степень - четное число)
int ExponentiationParity(int number, int rank)
{
	if (rank == 0) return 1;
	else {
		while (rank % 2 != 1)
		{
			number *= number;
			rank /= 2;
		}
		return number;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#pragma region Перевод десятичного числа в двоичную системы исчисления
	printf("ПРОГРАММА КОНВЕРТАЦИИ ИЗ ДЕСЯТИЧНОЙ СИСТЕМЫ ИСЧИСЛЕНИЯ В ДВОИЧНУЮ\n");
	int digit = Input("десятичное число: ");
	printf("В двоичной системе исчисления (с использованием рекурсии): ");
	BinaryConversionRecurs(digit);
	int temp = BinaryConversion(digit);
	printf("\nВ двоичной системе исчисления (без рекурсии): %d\n\n", temp);
	
#pragma endregion

#pragma region Возведение в степень
	printf("ПРОГРАММА ВОЗВЕДЕНИЕ В СТЕПЕНЬ ИСПОЛЬЗУЯ РЕКУРСИЮ, (ЧЕРЕЗ ЦИКЛЫ), ИСПОЛЬЗУЯ СВОЙСТВО ЧЕТНОСТИ СТЕПЕНИ\n\n");
	int number = Input("число: ");
	int rank = Input("степень: ");
	printf("Число %d в степени %d равно: %d\n", number, rank, ExponentiationRecurs(number, rank));
	printf("Число %d в степени %d равно: %d\n", number, rank, Exponentiation(number, rank));
	printf("Число %d в степени %d равно: %d\n\n", number, rank, rank % 2 ? Exponentiation(number, rank) : ExponentiationParity(number, rank));
#pragma endregion

	return 1;
}