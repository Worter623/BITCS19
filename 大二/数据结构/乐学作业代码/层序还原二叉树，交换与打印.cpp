#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode BioTree;

int depth = 0, level = 0;
char Tree[100] = { '\0' };

struct Node
{
	char data;
	BioTree LeftChild, RightChild;
};

BioTree NewLeaf(char x)
{
	BioTree p;
	p = (BioTree)malloc(sizeof(BioTree));
	p->data = x;
	p->LeftChild = NULL;
	p->RightChild = NULL;
	return p;
}

void CreateTree(BioTree head, int sum)
{
	depth = ceil(log(sum) / log(2));
	if (depth > level)
		depth--;
	else {
		char templ, tempr;
		templ = Tree[2 * sum - 1];
		tempr = Tree[2 * sum];
		if (templ == '#' || templ == '\0')
			head->LeftChild = NULL;
		else {
			head->LeftChild = NewLeaf(templ);
			CreateTree(head->LeftChild, sum * 2);
		}
		if (tempr == '#' || tempr == '\0')
			head->RightChild = NULL;
		else {
			head->RightChild = NewLeaf(tempr);
			CreateTree(head->RightChild, sum * 2 + 1);
		}
	}
}

void PrintTree(BioTree head, int degree)
{
	if (head != NULL) {
		for (int i = 0; i < degree; i++)
			printf("    ");
		printf("%c\n", head->data);
		PrintTree(head->LeftChild, degree + 1);
		PrintTree(head->RightChild, degree + 1);
	}
}

void PrintPreOrder(BioTree head)
{
	if (head != NULL) {
		printf("%c", head->data);
		PrintPreOrder(head->LeftChild);
		PrintPreOrder(head->RightChild);
	}
}

void PrintInOrder(BioTree head)
{
	if (head != NULL) {
		PrintInOrder(head->LeftChild);
		printf("%c", head->data);
		PrintInOrder(head->RightChild);
	}
}

void PrintPostOrder(BioTree head)
{
	if (head != NULL) {
		PrintPostOrder(head->LeftChild);
		PrintPostOrder(head->RightChild);
		printf("%c", head->data);
	}
}

int CountLeaf(BioTree head)
{
	int k=0;
	if (head->LeftChild == NULL && head->RightChild == NULL)
		k=1;
	if (head->LeftChild != NULL)
		k+=CountLeaf(head->LeftChild);
	if (head->RightChild != NULL)
		k+=CountLeaf(head->RightChild);
	return k;
}

BioTree Swap(BioTree head)
{
	BioTree temp;
	if (head == NULL)
		return NULL;
	temp = head->LeftChild;
	head->LeftChild = head->RightChild;
	head->RightChild = temp;
	Swap(head->RightChild);
	Swap(head->LeftChild);
	return NULL;
}

int main()
{
	int length;
	scanf("%s", &Tree);
	BioTree head = NewLeaf(Tree[0]),SwapHead= NewLeaf(Tree[0]);
	length = strlen(Tree);
	level = ceil(log(length) / log(2));
	CreateTree(head, 1);
	printf("BiTree\n");
	PrintTree(head, 0);
	printf("pre_sequence  : ");
	PrintPreOrder(head);
	printf("\nin_sequence   : ");
	PrintInOrder(head);
	printf("\npost_sequence : ");
	PrintPostOrder(head);
	printf("\n");
	int count=CountLeaf(head);
	printf("Number of leaf: %d\n", count);
	SwapHead = Swap(head);
	SwapHead = head;
	printf("BiTree swapped\n");
	PrintTree(SwapHead, 0);
	printf("pre_sequence  : ");
	PrintPreOrder(SwapHead);
	printf("\nin_sequence   : ");
	PrintInOrder(SwapHead);
	printf("\npost_sequence : ");
	PrintPostOrder(SwapHead);
	printf("\n");
}
