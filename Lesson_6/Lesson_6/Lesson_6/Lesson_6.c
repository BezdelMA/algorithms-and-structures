#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

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
int i = 0, l = 0, r = 0;

typedef struct TNode
{
	int data;
	struct TNode*left;
	struct TNode* right;
	struct TNode* parent;
} TNode;

typedef struct Students
{
	int id;
	char* name;
	int age;
	struct Students* left;
	struct Students* right;
	struct Students* parent;
}Students;

Students* searchNAME;

Students* newStudents(Students* parent, int id, char* name, int age)
{
	Students* students = (Students*)malloc(sizeof(Students));
	students->id = id;
	students->name = name;
	students->age = age;
	students->parent = parent;
	students->right = NULL;
	students->left = NULL;
	return students;
}

Students* Push(Students* students, int id, char* name, int age)
{
	if (students == NULL)
	{
		students = newStudents(students, id, name, age);
		return students;
	}
	if (students->id > id)
	{
		if (students->left != NULL)
			Push(students->left, id, name, age);
		else
		{
			students->left = newStudents(students, id, name, age);
			students->left->left = NULL;
			students->left->right = NULL;
		}
	}
	else
	{
		if (students->right != NULL)
			Push(students->right, id, name, age);
		else
		{
			students->right = newStudents(students, id, name, age);
			students->right->left = NULL;
			students->right->right = NULL;
		}
	}
	return students;
}

Students* SearchID(Students* students, int id)
{
	if (students == NULL)
		return NULL;
	while (students)
	{
		if (students->id == id)
		{
			students->left = NULL;
			students->right == NULL;
			students->parent = NULL;
			return students;
		}
		if (students->id > id)
			return SearchID(students->left, id);
		else
			return SearchID(students->right, id);
	}
}

Students* SearchNAME(Students* students, char* name)
{
	if (students == NULL)
		return NULL;
	if (strcmp(students->name, name) == 0)
	{
		students->left = NULL;
		students->right == NULL;
		students->parent = NULL;
		return students;
	}
	if (students->left || students->right)
	{
		if (students->left)
			SearchNAME(students->left, name);
		if (students->right)
			SearchNAME(students->right, name);
	}
}

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

//Input tree #2
TNode* tree_2(TNode* parent, int temp)
{
	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->left = NULL;
	node->right = NULL;
	node->data = temp;
	node->parent = parent;
	return node;
}

//Input Sort Tree
TNode* InputTree(TNode* node, int temp)
{
	if (node == NULL)
	{
		node = tree_2(NULL, temp);
		return node;
	}
	if (node->data > temp)
		//налево
	{
		if (node->left != NULL)
			InputTree(node->left, temp);
		else
		{
			node->left = tree_2(node, temp);
			node->left->left = NULL;
			node->left->right = NULL;
			node->left->data = temp;
		}
	}
	else //направо
	{
		if (node->right != NULL)
			InputTree(node->right, temp);
		else
		{
			node->right = tree_2(node, temp);
			node->right->left = node->right->right = NULL;
			node->right->data = temp;
		}
	}
	return node;
}

//Search in the tree by value
TNode* Search(TNode* node, int value)
{
	if (node == NULL)
		return NULL;
	if (value == node->data)
		return node;
	if (value < node->data)
		return Search(node->left, value);
	else
		return Search(node->right, value);
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
#pragma region Hash
	char str[100];
	printf("Input string: ");
	scanf("%s", &str);
	printf("Hash string: %d\n\n", MakeHash(str));
#pragma endregion

#pragma region Output Tree different way
	TNode* t = tree(a, NULL);
	preOrderTravers(t);
	printf("\n\n");
	inOrderTravers(t);
	printf("\n\n");
	postOrderTravers(t);
#pragma endregion

#pragma region Sorted Tree
	printf("\n\n");
	i = 0;
	TNode* t_2;
	t_2 = NULL;
	t_2 = InputTree(t_2, arr[i]);
	for (i = 1; i < 10; i++)
	{
		InputTree(t_2, arr[i]);
	}
	preOrderTravers(t_2);
#pragma endregion

#pragma region Search in the tree by value
TNode* search = Search(t_2, 11);
#pragma endregion

	Students* st = NULL;
	st = Push(st, 40, "Mikhail", 25);
	Push(st, 17, "Anna", 28);
	Push(st, 32, "Maria", 37);
	Push(st, 16, "Artem", 27);
	Push(st, 18, "Nikolay", 26);
	Push(st, 67, "Natalia", 30);
	Push(st, 48, "Yuriy", 16);
	Push(st, 52, "Valentin", 34);
	Push(st, 14, "Andrew", 15);
	Push(st, 37, "Stanislav", 16);
	Push(st, 29, "Taras", 34);
	Push(st, 43, "Petr", 41);
	Push(st, 2, "Aleksey", 18);

	searchNAME = SearchNAME(st, "Anna");
	Students* searchID = SearchID(st, 18);
	//Students* searchAGE = SerachAGE(st, 34);

	return 1;
}