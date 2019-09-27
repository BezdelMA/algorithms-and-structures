#include <stdio.h>
#include <Windows.h>
#include <math.h>
#pragma warning(disable : 4996)

//Ввод данных с клавиатуры
int Input(char* text)
{
	printf("Введите %s", text);
	int result;
	scanf("%d", &result);
	return result;
}

//Проверка возраста для подстановки текста год, года, лет
char* CheckAge(int age)
{
	char* text = "";
	int temp = age % 10;
	if ((age > 20 & temp == 1) || age == 1)
		text = "год";
	else if ((age > 20 & (temp >= 2 & temp <= 4)) || (age > 1 & age < 4))
		text = "года";
	else if (age >= 20 & (temp >= 5 & temp <= 9 || temp == 0) || (age >= 5 & age < 20))
		text = "лет";
	return text;
}

//Функция проверки наличия нечетных цифр в числе
char* CheckNumber(int number)
{
	char* text = "";
	while (number >= 1)
	{
		int temp = number % 10;
		if (temp != 2 & temp % 2 == 1 || temp == 1)
		{
			text = "есть нечетные цифры";
			break;
		}
		else text = "нет нечетных цифр";
		number /= 10;
	}
	return text;
}

//Функция деление чисел с использованием сложения и вычитания
int Division(int n, int k)
{
	int chastnoe = 0;
	while (n >= k)
	{
		chastnoe++;
		n -= k;
	}
	return chastnoe;
}

//Решение квадратного уравнения
int Solution(int a, int b, int c)
{
	int d = pow(b, 2) - (4 * a * c);
	if (d < 0) return 0;
	else if (d == 0) return 1;
	else return 2;
}

//Проверка цветов поля шахматной доски
int CheckChess(int x, int y)
{
	int tempX = x % 2;
	int tempY = y % 2;
	if ((tempY == 1 & tempX == 0) || (tempY == 0 & tempX == 1)) return 1;
	else return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#pragma region Индекс массы тела
	printf("ПРОГРАММА РАСЧЕТА ИНДЕКСА МАССЫ ТЕЛА\n");
	float h = ((float)Input(" рост в сантиметрах: ")) / 100;
	int w = Input(" вес: ");
	float i = w / (h*h);
	printf("Индекс массы Вашего тела: %.2f\n\n", i);


#pragma endregion

#pragma region Обмен значениями переменных без ипользования третьей
	printf("ПРОГРАММА ОБМЕНА ЗНАЧЕНИЯМИ ПЕРЕМЕННЫХ БЕЗ ИСПОЛЬЗОВАНИЯ ТРЕТЬЕЙ (z = 10, y = 38)\n");
	int z = 10;
	int y = 38;
	z = z ^ y;
	y = y ^ z;
	z = z ^ y;
	printf("После проведения операции обмена значениями: z = %d и y = %d\n\n", z, y);
#pragma endregion

#pragma region Нахождение корня квадратного уровнения типа ax^2 + bx + c = 0;
	printf("ПРОГРАММА НАХОЖДЕНИЯ КОРНЯ(ЕЙ) КВАДРАТНОГО УРАВНЕНИЯ ТИПА ax^2 + bx + c = 0\n");
	int a = Input(" значение A: "),	b = Input(" значение B: "), c = Input(" значение C: ");
	printf("Осуществляется решение уравнения %dx^2 + %dx + %d = 0\n", a, b, c);
	int temp = Solution(a, b, c);
	float x1, x2;
	if (temp == 1)
	{
		x1 = (-1 * b) / (2 * a);
		printf("Уравнение имеет 1 решение: %.2f\n\n", x1);
	}
	else if (temp == 2)
	{
		x1 = ((-1 * b) + pow((pow(b, 2) - (4 * a * c)), 0.5)) / (2 * a);
		x2 = ((-1 * b) - pow((pow(b, 2) - (4 * a * c)), 0.5)) / (2 * a);
		printf("Уравнение имеет 2 решения: %.2f и %.2f\n\n", x1, x2);
	}
	else printf("Уравнение не имеет решений\n\n");
	
#pragma endregion

#pragma region Подпись слов год, года, лет
	printf("ПРОГРАММА ПОДПИСИ СЛОВ ГОД, ГОДА, ЛЕТ\n");
	int age = Input(" Ваш возраст: ");
	char* text = CheckAge(age);
	printf("Вам %d %s\n\n", age, text);
#pragma endregion

#pragma region Определение одноцветности двух полей шахматной доски
	printf("ПРОГРАММА ОПРЕДЕЛЕНИЯ ОДНОЦВЕТНОСТИ ДВУХ ПОЛЕЙ ШАХМАТНОЙ ДОСКИ\n");
	x1 = 4;
	x2 = 6;
	int y1 = 7, y2 = 4;
	int temp1 = CheckChess(x1, y1);
	int temp2 = CheckChess(x2, y2);
	printf("Заданные поля с координатами (4, 7) и (6, 4) имеют %s\n\n", (temp1 == temp2) ? "одинацовый цвет" : "разные цвета");
#pragma endregion

#pragma region Определение наличия нечетных цифр в числе
	printf("ПРОГРАММА ОПРЕДЕЛЕНИЯ НАЛИЧИЯ НЕЧЕТНЫХ ЦИФР В ЧИСЛЕ\n");
	int number = Input(" любое число: ");
	printf("В заданном числе %d %s\n\n", number, CheckNumber(number));
#pragma endregion

#pragma region Нахождение частного и остатка от деления через операции сложения и вычитания
	printf("ПРОГРАММА НАХОЖДЕНИЯ ЧАСТНОГО И ОСТАТКА ОТ ДЕЛЕНИЯ ЧЕРЕЗ ОПЕРАЦИИ СЛОЖЕНИЯ И ВЫЧИТАНИЯ\n");
	int n = Input(" значение 1 числа: ");
	int k = Input(" значение 2 числа: ");
	int chastnoe = Division(n, k);
	int ostatok = n - (k*chastnoe);
	printf("Частное от деления значений %d и %d равно: %d. Остаток от деления - %d\n\n", n, k, chastnoe, ostatok);
#pragma endregion

#pragma region Алгоритм с урока (Нахождение средней оценки ученика (не более 10 оценок), выход из программы при вводе "-1", без повторяющихся строк в коде)
	printf("АЛГОРИТМ РАСЧЕТА СРЕДНЕЙ ОЦЕНКИ УЧЕНИКА (не более 10 оценок, выход из цикла при вводе <-1>, без повторений в коде)\n");
	int sum = 0, counter = 0, score;
	printf("Введите оценки через Enter (или - 1 для выхода):");
	while (counter < 10)
	{
		scanf("%d", &score);
		if (score == -1) break;
		counter++;
		sum += score;
	}
	if (counter > 0) printf("Средняя оценка ученика: %.2f\n\n", (float)sum / (float)counter);
	else printf("Нет оценок для вычисления среднего значения\n\n");
#pragma endregion

	return 1;
}