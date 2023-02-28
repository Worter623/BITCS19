#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int PriorityQueue[10000];
//堆顶元素最小
//上浮前size已经+1
void PercolateUp(int PriorityQueue[], int size,int insert_element)
{
	int i;
	for (i = size; PriorityQueue[i / 2] > insert_element; i /= 2)
		PriorityQueue[i] = PriorityQueue[i / 2];
	PriorityQueue[i] = insert_element;
}

void PercolateDown(int PriorityQueue[], int begin, int size)
{
	int temp = PriorityQueue[begin], child;
	for (child = 2*begin; child <= size;child*=2)
	{
		if (child < size && PriorityQueue[child + 1] < PriorityQueue[child])
			child++;//找出左右孩子中更小的那个
		if (temp <= PriorityQueue[child])
			break;//如果该父亲比左右孩子都小，即已经确定到了该父亲要下滤的位置
		PriorityQueue[begin] = PriorityQueue[child];//把孩子放到父亲的位置
		begin = child;
	}
	PriorityQueue[begin] = temp;//父亲放到下滤的位置
}
