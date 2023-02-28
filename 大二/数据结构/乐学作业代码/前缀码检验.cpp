#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode BTree;

struct Node
{
	int data;
	BTree LeftChild, RightChild;
};

void CreateNewNode(BTree position,int length,int i)
{
	position->LeftChild = position->RightChild = NULL;
	if (i == length - 1)
		position->data = 1;
	else
		position->data = 0;
}

int main()
{
	int i,n,flag=0,length;
	char code[100009];
	BTree temp,tree = (BTree)malloc(sizeof(struct Node));
	tree->data = 0;
	tree->LeftChild = tree->RightChild = NULL;
	scanf("%d\n", &n);
	while (n--)
	{
		memset(code, 0, sizeof(code));
		scanf("%s", &code);
		length = strlen(code);
		temp = tree;
		for (i = 0; i < length; i++)
		{
			if (code[i] == '1')
			{
				if (temp->LeftChild == NULL)
				{
					temp->LeftChild = (BTree)malloc(sizeof(struct Node));
					temp = temp->LeftChild;
					CreateNewNode(temp,length,i);
				}
				else
				{
					if (temp->LeftChild->data == 1 || i == length - 1)
					{
						flag = 1;
						break;
					}
					else
						temp = temp->LeftChild;
				}
			}
			else
			{
				if (temp->RightChild == NULL)
				{
					temp->RightChild = (BTree)malloc(sizeof(struct Node));
					temp = temp->RightChild;
					CreateNewNode(temp, length, i);
				}
				else
				{
					if (temp->RightChild->data == 1 || i == length - 1)
					{
						flag = 1;
						break;
					}
					else
						temp = temp->RightChild;
				}
			}
		}
		if (flag == 1)
			break;
	}
	if (flag == 0)
		printf("YES\n");
	else
		printf("%s\n", code);
}
