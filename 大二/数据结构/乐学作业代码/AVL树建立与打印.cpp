#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode AVLTree;

struct Node
{
	char data;
	AVLTree LeftChild, RightChild;
	int height;
};

int Height(AVLTree head)
{
	if (head == NULL)
		return -1;
	return head->height;
}

AVLTree SingleRotateWithRight(AVLTree head)
{
	AVLTree p = head->RightChild;
	head->RightChild = p->LeftChild;
	p->LeftChild = head;
	head->height = max(Height(head->RightChild), Height(head->LeftChild)) + 1;
	p->height = max(Height(p->RightChild), Height(p->LeftChild)) + 1;
	return p;
}

AVLTree SingleRotateWithLeft(AVLTree head)
{
	AVLTree p = head->LeftChild;
	head->LeftChild = p->RightChild;
	p->RightChild = head;
	head->height = max(Height(head->RightChild), Height(head->LeftChild)) + 1;
	p->height = max(Height(p->RightChild), Height(p->LeftChild)) + 1;
	return p;
}

AVLTree DoubleRotateWithLeft(AVLTree head)
{
	head->LeftChild = SingleRotateWithRight(head->LeftChild);
	return SingleRotateWithLeft(head);
}

AVLTree DoubleRotateWithRight(AVLTree head)
{
	head->RightChild = SingleRotateWithLeft(head->RightChild);
	return SingleRotateWithRight(head);
}

AVLTree CreateTree(AVLTree head, char temp)
{
	AVLTree T = head;
	if (T == NULL)
	{
		T = (AVLTree)malloc(sizeof(struct Node));
		T->data = temp;
		T->height = 0;
		T->LeftChild = NULL;
		T->RightChild = NULL;
	}
	else
	{
		if (temp < T->data)
		{
			T->LeftChild = CreateTree(T->LeftChild, temp);
			if (Height(T->LeftChild) - Height(T->RightChild) == 2)
				if (temp < T->LeftChild->data)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
		}
		else
		{
			T->RightChild = CreateTree(T->RightChild, temp);
			if (Height(T->RightChild) - Height(T->LeftChild) == 2)
				if(temp>T->RightChild->data)
					T = SingleRotateWithRight(T);
				else
					T= DoubleRotateWithRight(T);
		}
	}
	T->height = max(Height(T->LeftChild), Height(T->RightChild)) + 1;
	return T;
}

void PrintTree(AVLTree head, int degree)
{
	if (head != NULL) {
		if(head->RightChild)
			PrintTree(head->RightChild, degree + 1);
		for (int i = 0; i < degree; i++)
			printf("    ");
		printf("%c\n", head->data);
		if(head->LeftChild)
			PrintTree(head->LeftChild, degree + 1);
	}
}

void PrintPreOrder(AVLTree head)
{
	if (head != NULL) {
		printf("%c", head->data);
		PrintPreOrder(head->LeftChild);
		PrintPreOrder(head->RightChild);
	}
}

void PrintInOrder(AVLTree head)
{
	if (head != NULL) {
		PrintInOrder(head->LeftChild);
		printf("%c", head->data);
		PrintInOrder(head->RightChild);
	}
}

void PrintPostOrder(AVLTree head)
{
	if (head != NULL) {
		PrintPostOrder(head->LeftChild);
		PrintPostOrder(head->RightChild);
		printf("%c", head->data);
	}
}
int main()
{
	char input[100];
	scanf("%s", &input);
	AVLTree head = (AVLTree)malloc(sizeof(struct Node));
	head->data = input[0];
	head->height = 0;
	head->RightChild = NULL;
	head->LeftChild = NULL;
	int i, length;
	length = strlen(input);
	for(i=1;i<length;i++)
		head = CreateTree(head, input[i]);
	printf("Preorder: ");
	PrintPreOrder(head);
	printf("\nInorder: ");
	PrintInOrder(head);
	printf("\nPostorder: ");
	PrintPostOrder(head);
	printf("\nTree:\n");
	PrintTree(head, 0);
}


