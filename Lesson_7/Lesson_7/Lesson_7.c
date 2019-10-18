#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#pragma warning(disable : 4996)

int mass[7][7] = {
		{0,1,1,1,1,1,0},
		{1,0,0,0,1,0,1},
		{1,0,0,1,0,1,0},
		{1,0,1,0,0,1,1},
		{1,1,0,0,0,0,0},
		{1,0,1,1,0,0,0},
		{0,1,0,1,0,0,0}
	};
int spent[7] = { 0 };
int spentStackRecurs[7] = { 0 };
int spentStack_2[7] = { 0 };
int j, k = 0;
int jMax = 7;

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* parent;
}Node;

Node* queue;
Node* stackRecurs;
Node* stack_2;
Node* result;
Node* resultStackRecurs;
Node* resultStack_2;

Node* Push(Node* queue, int data)
{
	if (queue == NULL)
	{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->parent = queue;
		temp->next = NULL;
		temp->data = data;
		queue = temp;
	}
	else
	{
		if (queue->next == NULL)
		{
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->parent = queue;
			temp->next = NULL;
			temp->data = data;
			queue->next = temp;
		}
		else Push(queue->next, data);
	}
	return queue;
}

Node* Pop(Node* queue)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = queue->data;
	temp->next = queue->next;
	temp->parent = queue->parent;
	if (queue->next != NULL)
	{
		queue->data = queue->next->data;
		queue->parent = NULL;
		queue->next = queue->next->next;
	}
	else
	{
		queue = NULL;
		return queue;
	}

	return temp;
}

int PopStack(Node* stack)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (stack->next)
		temp = PopStack(stack->next);
	else
	{
		temp->data = stack->data;
		temp->next = temp->parent = NULL;
	}
	return temp;
}

void PrintQueue(Node* queue)
{
	printf("%d ", queue->data);
	while (queue->next)
	{
		if (queue->next)
		PrintQueue(queue->next);
		return;
	}
}

void byPassWidth(int i)
{
	if (spent[i] == 0)
	{
		spent[i] = 1;
		result = Push(result, i);
		for (j = 0; j < jMax; j++)
		{
			if (mass[i][j])
				if (spent[j] == 0)
					queue = Push(queue, j);
		}
		k = 0;
		for (j = 0; j < jMax; j++)
		{
			if (spent[j] == 1)
				k += 1;
		}
		if (k < jMax)
		{
			while (queue)
			{
				if (spent[queue->data] == 1)
					Pop(queue);
				else break;
			}
		}
		else return;
		if (queue)
		{

			byPassWidth(Pop(queue)->data);
			return;
		}
	}
}

void byPassDepthRecurs(int i)
{
	if (spentStackRecurs[i] == 0)
	{
		spentStackRecurs[i] = 1;
		resultStackRecurs = Push(resultStackRecurs, i);
		for (j = 0; j < jMax; j++)
		{
			if (mass[i][j] == 1)
				if (spentStackRecurs[j] == 0)
					stackRecurs = Push(stackRecurs, j);
		}
		if (stackRecurs)
		{
			Node* temp = PopStack(stackRecurs);
			byPassDepthRecurs(temp->data);
			return;
		}
	}
	stackRecurs = PopStack(stackRecurs);
}

void byPassDepth_2(int i)
{
	while (i < 10)
	{
		if (spentStack_2[i] == 0)
		{
			spentStack_2[i] = 1;
			resultStack_2 = Push(resultStack_2, i);
			for (j = 0; j < jMax; j++)
			{
				if (mass[i][j] == 1)
					if (spentStack_2[j] == 0)
						stack_2 = Push(stack_2, j);
			}
		}
		if (stack_2->next == NULL)
			break;
		else
		{
			Node* temp = PopStack(stack_2->next);
			i = temp->data;
			stack_2 = PopStack(stack_2);
		}
	}
}

int main()
{
	byPassWidth(1);
	PrintQueue(result);
	printf("\n\n");
	byPassDepthRecurs(1);
	PrintQueue(resultStackRecurs);
	printf("\n\n");
	byPassDepth_2(1);
	PrintQueue(resultStack_2);
}
