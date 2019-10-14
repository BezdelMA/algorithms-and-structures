#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#pragma warning(disable : 4996)

int MakeHash(char str[100])
{
	int i, hash = 0;
	for(i = 0; i < strlen(str); i++)
	{
		hash += str[i];
	}
	return hash;
}

int arr[10] = { 16, 18, 63, 11, 19, 64, 15, 77, 84, 14 };
int a = sizeof(arr) / sizeof(int);
int i = 0;

typedef struct TNode
{
	int data;
	struct TNode*left;
	struct TNode* right;
	struct TNode* parent;
} TNode;

//Input tree
TNode* tree(int a, TNode* parent)
{
	TNode* node;
	if (a == 0)
		node = NULL;
	else
	{
		node = (TNode*)malloc(sizeof(TNode));
		int temp = arr[i];
		node->data = temp;
		node->parent = parent;
		int nl = a / 2;
		int nr = a - nl - 1;
		i++;
		node->left = tree(nl, node);
		node->right = tree(nr, node);
	}
	return node;
}

TNode* tree_2(TNode* parent, int temp)
{
	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->left = NULL;
	node->right = NULL;
	node->data = temp;
	node->parent = parent;
	return node;
}

TNode* InputTree(TNode* node)
{
	int temp = arr[i];
	if (node == NULL)
		node = tree_2(NULL, temp);
	while (node->data)
	{
		if (node->data > temp)
			if (node->left)
				node->data = node->right;
			else
				node->left = tree_2(node->data, temp);
		else if (node->data < temp)
			if (node->right)
				node->data = node->right;
			else
				node->right = tree_2(node->data, temp);
		if (i < 10)
			temp = arr[++i];
		else break;
	}
	return node;
}

void preOrderTravers(TNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
			{
				preOrderTravers(root->left);
			}
			else printf("NULL");
			printf(",");
			if (root->right)
			{
				preOrderTravers(root->right);
			}
			else printf("NULL");
			printf(")");
		}
	}
}

void inOrderTravers(TNode* root)
{
	if (root)
	{
		printf("(");
		if (root->left)
			inOrderTravers(root->left);
		else printf("NULL");
		printf(",");
		printf("%d", root->data);
		if (root->right)
			inOrderTravers(root->right);
		printf(")");
	}
}

void postOrderTravers(TNode* root)
{
	if (root)
	{
		printf("(");
		if(root->left)
		{
			postOrderTravers(root->left);
		}
		else printf("NULL");
		printf(",");
		if (root->right)
		{
			postOrderTravers(root->right);
		}
		printf("%d", root->data);
		printf(")");
	}
}

int main()
{
	char str[100];
	//printf("Input string: ");
	//scanf("%s", &str);
	//printf("Hash string: %d\n\n", MakeHash(str));
	TNode* t = tree(a, NULL);
	preOrderTravers(t);
	printf("\n\n");
	inOrderTravers(t);
	printf("\n\n");
	postOrderTravers(t);

	i = 0;
	TNode* t_2 = InputTree(NULL);
	preOrderTravers(t_2);
}