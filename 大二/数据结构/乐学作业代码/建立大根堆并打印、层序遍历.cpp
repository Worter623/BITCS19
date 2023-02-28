#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode BiTree;

struct Node
{
	int data;
	BiTree LeftChild, RightChild;
};

BiTree CreateTree(BiTree head, int temp)
{
	BiTree T = head;
	if (T == NULL||T->data==0)
	{
		T = (BiTree)malloc(sizeof(struct Node));
		T->data = temp;
		T->LeftChild = NULL;
		T->RightChild = NULL;
	}
	else
	{
		if (temp > T->data)
			T->RightChild = CreateTree(T->RightChild, temp);
		else
			if (temp < T->data)
				T->LeftChild= CreateTree(T->LeftChild, temp);
	}
	return T;
}

void PrintTree(BiTree head, int degree)
{
	if (head != NULL) {
		PrintTree(head->LeftChild, degree + 1);
		for (int i = 0; i < degree; i++)
			printf("    ");
		printf("%d\n", head->data);
		PrintTree(head->RightChild, degree + 1);
	}
}

void PrintInOrder(BiTree head)
{
	if (head != NULL) {
		PrintInOrder(head->LeftChild);
		printf(" %d", head->data);
		PrintInOrder(head->RightChild);
	}
}

int main()
{
	int temp;
	BiTree head = (BiTree)malloc(sizeof(struct Node));
	head->data = 0;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == 0)
			break;
		else
			head = CreateTree(head, temp);
	}
	PrintTree(head, 0);
	printf("\n");
	PrintInOrder(head);
	printf("\n");
}


