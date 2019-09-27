#include <stdio.h>
#include <Windows.h>
#include <math.h>
#pragma warning(disable : 4996)

//���� ������ � ����������
int Input(char* text)
{
	printf("������� %s", text);
	int result;
	scanf("%d", &result);
	return result;
}

//�������� �������� ��� ����������� ������ ���, ����, ���
char* CheckAge(int age)
{
	char* text = "";
	int temp = age % 10;
	if ((age > 20 & temp == 1) || age == 1)
		text = "���";
	else if ((age > 20 & (temp >= 2 & temp <= 4)) || (age > 1 & age < 4))
		text = "����";
	else if (age >= 20 & (temp >= 5 & temp <= 9 || temp == 0) || (age >= 5 & age < 20))
		text = "���";
	return text;
}

//������� �������� ������� �������� ���� � �����
char* CheckNumber(int number)
{
	char* text = "";
	while (number >= 1)
	{
		int temp = number % 10;
		if (temp != 2 & temp % 2 == 1 || temp == 1)
		{
			text = "���� �������� �����";
			break;
		}
		else text = "��� �������� ����";
		number /= 10;
	}
	return text;
}

//������� ������� ����� � �������������� �������� � ���������
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

//������� ����������� ���������
int Solution(int a, int b, int c)
{
	int d = pow(b, 2) - (4 * a * c);
	if (d < 0) return 0;
	else if (d == 0) return 1;
	else return 2;
}

//�������� ������ ���� ��������� �����
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

#pragma region ������ ����� ����
	printf("��������� ������� ������� ����� ����\n");
	float h = ((float)Input(" ���� � �����������: ")) / 100;
	int w = Input(" ���: ");
	float i = w / (h*h);
	printf("������ ����� ������ ����: %.2f\n\n", i);


#pragma endregion

#pragma region ����� ���������� ���������� ��� ������������ �������
	printf("��������� ������ ���������� ���������� ��� ������������� ������� (z = 10, y = 38)\n");
	int z = 10;
	int y = 38;
	z = z ^ y;
	y = y ^ z;
	z = z ^ y;
	printf("����� ���������� �������� ������ ����������: z = %d � y = %d\n\n", z, y);
#pragma endregion

#pragma region ���������� ����� ����������� ��������� ���� ax^2 + bx + c = 0;
	printf("��������� ���������� �����(��) ����������� ��������� ���� ax^2 + bx + c = 0\n");
	int a = Input(" �������� A: "),	b = Input(" �������� B: "), c = Input(" �������� C: ");
	printf("�������������� ������� ��������� %dx^2 + %dx + %d = 0\n", a, b, c);
	int temp = Solution(a, b, c);
	float x1, x2;
	if (temp == 1)
	{
		x1 = (-1 * b) / (2 * a);
		printf("��������� ����� 1 �������: %.2f\n\n", x1);
	}
	else if (temp == 2)
	{
		x1 = ((-1 * b) + pow((pow(b, 2) - (4 * a * c)), 0.5)) / (2 * a);
		x2 = ((-1 * b) - pow((pow(b, 2) - (4 * a * c)), 0.5)) / (2 * a);
		printf("��������� ����� 2 �������: %.2f � %.2f\n\n", x1, x2);
	}
	else printf("��������� �� ����� �������\n\n");
	
#pragma endregion

#pragma region ������� ���� ���, ����, ���
	printf("��������� ������� ���� ���, ����, ���\n");
	int age = Input(" ��� �������: ");
	char* text = CheckAge(age);
	printf("��� %d %s\n\n", age, text);
#pragma endregion

#pragma region ����������� ������������� ���� ����� ��������� �����
	printf("��������� ����������� ������������� ���� ����� ��������� �����\n");
	x1 = 4;
	x2 = 6;
	int y1 = 7, y2 = 4;
	int temp1 = CheckChess(x1, y1);
	int temp2 = CheckChess(x2, y2);
	printf("�������� ���� � ������������ (4, 7) � (6, 4) ����� %s\n\n", (temp1 == temp2) ? "���������� ����" : "������ �����");
#pragma endregion

#pragma region ����������� ������� �������� ���� � �����
	printf("��������� ����������� ������� �������� ���� � �����\n");
	int number = Input(" ����� �����: ");
	printf("� �������� ����� %d %s\n\n", number, CheckNumber(number));
#pragma endregion

#pragma region ���������� �������� � ������� �� ������� ����� �������� �������� � ���������
	printf("��������� ���������� �������� � ������� �� ������� ����� �������� �������� � ���������\n");
	int n = Input(" �������� 1 �����: ");
	int k = Input(" �������� 2 �����: ");
	int chastnoe = Division(n, k);
	int ostatok = n - (k*chastnoe);
	printf("������� �� ������� �������� %d � %d �����: %d. ������� �� ������� - %d\n\n", n, k, chastnoe, ostatok);
#pragma endregion

#pragma region �������� � ����� (���������� ������� ������ ������� (�� ����� 10 ������), ����� �� ��������� ��� ����� "-1", ��� ������������� ����� � ����)
	printf("�������� ������� ������� ������ ������� (�� ����� 10 ������, ����� �� ����� ��� ����� <-1>, ��� ���������� � ����)\n");
	int sum = 0, counter = 0, score;
	printf("������� ������ ����� Enter (��� - 1 ��� ������):");
	while (counter < 10)
	{
		scanf("%d", &score);
		if (score == -1) break;
		counter++;
		sum += score;
	}
	if (counter > 0) printf("������� ������ �������: %.2f\n\n", (float)sum / (float)counter);
	else printf("��� ������ ��� ���������� �������� ��������\n\n");
#pragma endregion

	return 1;
}