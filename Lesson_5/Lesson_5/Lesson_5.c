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

void Copy(char value)
{
	if (StackCopy.size >= StackCopy.maxSize)
	{
		printf("StackCopy is all, sorry");
		return;
	}

	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = StackCopy.head;
	StackCopy.head = tmp;
	StackCopy.size++;
}

void PushQueue(char value)
{
	if (Queue.size_2 >= Queue.maxSize_2)
	{
		printf("Stack is all, sorry");
		return;
	}
	Node_2* temp = (Node_2*)malloc(sizeof(Node_2));
	temp->value = value;
	temp->next = Queue.tail;
	temp->prev = Queue.head;
	Queue.tail= temp;
}

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

void PrintQueue(struct Queue Queue)
{
	Node *current = Queue.head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}

void PrintStack(struct Stack Stack)
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}

void CopyStack(struct Stack Stack, struct Stack StackCopy)
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		Copy(current->value);
		current = current->next;
	}
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#pragma region Создание Стека и копирование в другой односвязный список Стека
	printf("Создание структуры Stack на основе односвязаного списка. Вывод данных: \n");
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

	printf("\nКопирование односвязного списка в структуру StackCopy\n");
	StackCopy.maxSize = Stack.maxSize;
	StackCopy.head = NULL;
	CopyStack(Stack, StackCopy);
	PrintStack(StackCopy);
#pragma endregion
	
	printf("\nСоздание структуры Queue на основе двусвязного списка. Вывод данных: \n\n");
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
	return 1;
}