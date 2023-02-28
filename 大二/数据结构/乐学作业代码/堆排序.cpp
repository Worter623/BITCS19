#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LeftChild(i) (2*i)
#define RightChild(i) (2*i+1)

void PercDown(int heap[], int i, int n)
{
	int temp = heap[i], child;
	for (child = LeftChild(i); child <= n; child *= 2)
	{
		if (child<n && heap[child + 1] > heap[child])
			child++;//找出左右孩子中更大的那个
		if (temp >= heap[child])
			break;//如果该父亲比左右孩子都大，即已经确定到了该父亲要下滤的位置
		heap[i] = heap[child];//把孩子放到父亲的位置
		i = child;
	}
	heap[i] = temp;// 父亲放到下滤的位置
}

void Print(int heap[],int n)
{
	for (int i = 1; i < 1+n; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

void HeapSort(int heap[], int n)
{
	int temp,i;
	for (i = n/2+1; i >0; i--)
		PercDown(heap, i, n);
	Print(heap,n);
	heap[1] = heap[n];
}

int main()
{
	int n, i,heap[10010];
	scanf("%d", &n);
	for(i=1;i<1+n;i++)
		scanf("%d", &heap[i]);
	HeapSort(heap, n);
	HeapSort(heap, n-1);
	HeapSort(heap, n-2);
}