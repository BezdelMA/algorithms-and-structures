#include <stdio.h>
#include <Windows.h>
#pragma warning(disable : 4996)

int Input(char* text)
{
	int temp;
	printf("������� %s", text);
	scanf("%d", &temp);
	return temp;
}

void BinaryConversionRecurs(int digit)
{
	if (digit > 1)
			BinaryConversionRecurs(digit / 2);
	printf("%d", digit % 2);
}

//������� �� ���������� ������� ���������� � ��������
int BinaryConversion(int digit)
{
	int temp = 0;
	int mass[10] = { 0 };
	int i = 0;
	
	//����������� ������� �� ������� �� 2
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
	
	//���������� ���������� � ���������� ���� int ��� �������� � main
	for (i = 9; i >= 0; i--)
		temp = temp * 10 + mass[i];
	return temp;
}

//���������� � ������� � �������������� ��������
int ExponentiationRecurs(int number, int rank)
{
	if (rank == 0) return 1;
	else return ExponentiationRecurs(number, rank - 1) * number;
}

//���������� � ������� ��� ������������� �������� (����� ���� FOR)
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

//���������� � ������� ��������� �������� �������� ������� (���������� ������ ����� ������� - ������ �����)
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

#pragma region ������� ����������� ����� � �������� ������� ����������
	printf("��������� ����������� �� ���������� ������� ���������� � ��������\n");
	int digit = Input("���������� �����: ");
	printf("� �������� ������� ���������� (� �������������� ��������): ");
	BinaryConversionRecurs(digit);
	int temp = BinaryConversion(digit);
	printf("\n� �������� ������� ���������� (��� ��������): %d\n\n", temp);
	
#pragma endregion

#pragma region ���������� � �������
	printf("��������� ���������� � ������� ��������� ��������, (����� �����), ��������� �������� �������� �������\n\n");
	int number = Input("�����: ");
	int rank = Input("�������: ");
	printf("����� %d � ������� %d �����: %d\n", number, rank, ExponentiationRecurs(number, rank));
	printf("����� %d � ������� %d �����: %d\n", number, rank, Exponentiation(number, rank));
	printf("����� %d � ������� %d �����: %d\n\n", number, rank, rank % 2 ? Exponentiation(number, rank) : ExponentiationParity(number, rank));
#pragma endregion

	return 1;
}