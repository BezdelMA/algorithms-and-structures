#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <malloc.h>

struct TNode
{
	char value;
	struct TNode *next;
};
typedef struct TNode Node;

struct TNode_2
{
	char value;
	struct TNode_2* next;
	struct TNode_2* prev;
};
typedef struct TNode_2 Node_2;

struct Queue
{
	struct TNode_2* head;
	struct TNode_2* tail;
	int size_2, maxSize_2;
};
struct Queue Queue;

struct Stack
{
	Node *head;
	int size, maxSize;
};
struct Stack Stack, StackCopy;

//���������� ������ �������� � Stack
void Push(char value)
{
	if (Stack.size >= Stack.maxSize)
	{
		printf("Stack is all, sorry");
		return;
	}

	Node *temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->next = Stack.head;
	Stack.head = temp;
	Stack.size++;
}

//�������� ���������� ���������� �������� � Stack
char Pop()
{
	if (Stack.size == 0)
	{
		printf("Stack is null, sorry");
		return 0;
	}

	Node *next = NULL;
	char value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	free(next);
	Stack.size--;
	return value;
}

//����� �� ����� Stack
void PrintStack(struct Stack Stack)
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}

//��������������� ������� ����������� �� ������ ������ � ������
void Copy(char value)
{
	if (StackCopy.size >= StackCopy.maxSize)
	{
		printf("StackCopy is all, sorry");
		return;
	}

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = StackCopy.head;
	StackCopy.head = tmp;
	StackCopy.size++;
}

//����������� �� ������ ������ � ������
void CopyStack(struct Stack Stack, struct Stack StackCopy)
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		Copy(current->value);
		current = current->next;
	}
}

//���������� ������ �������� � ������� Queue
void PushQueue(char value)
{
	if (Queue.size_2 >= Queue.maxSize_2)
	{
		printf("Queue is all, sorry");
		return;
	}
	Node_2* temp = (Node_2*)malloc(sizeof(Node_2));
	temp->value = value;
	temp->next = NULL;
	temp->prev = Queue.tail;
	if (Queue.tail)
		Queue.tail->next = temp;
	Queue.tail = temp;
	if (Queue.head == NULL)
		Queue.head = temp;

	Queue.size_2++;
}

//����� �� ����� ������� Queue
void PrintQueue(struct Queue Queue)
{
	Node_2* current = Queue.head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#pragma region �������� ����� � ����������� � ������ ����������� ������ �����
	printf("�������� ��������� Stack �� ������ ������������� ������. ����� ������: \n");
	Stack.maxSize = 10;
	Stack.head = NULL;
	Push('M');
	Push('i');
	Push('k');
	Push('h');
	Push('a');
	Push('i');
	Push('l');
	Pop();
	PrintStack(Stack);

	printf("\n����������� ������������ ������ � ��������� StackCopy\n");
	StackCopy.maxSize = Stack.maxSize;
	StackCopy.head = NULL;
	CopyStack(Stack, StackCopy);
	PrintStack(StackCopy);
#pragma endregion
	
#pragma region �������� ������� �� ������ ����������� ������
	printf("\n�������� ��������� Queue �� ������ ����������� ������. ����� ������: \n\n");
	Queue.tail = NULL;
	Queue.maxSize_2 = 10;
	PushQueue('M');
	PushQueue('i');
	PushQueue('k');
	PushQueue('h');
	PushQueue('a');
	PushQueue('i');
	PushQueue('l');
	PrintQueue(Queue);

#pragma endregion

	return 1;
}