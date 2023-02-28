#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int median[1000], size_median = 0;

int Median3(int numbers[], int left, int right)
{
	int middle = (right + left) / 2;
	if (numbers[left] > numbers[middle])
		swap(numbers[left], numbers[middle]);
	if (numbers[left] > numbers[right])
		swap(numbers[left], numbers[right]);
	if (numbers[middle] > numbers[right])
		swap(numbers[middle], numbers[right]);
	swap(numbers[middle], numbers[right-1]);
	median[size_median] = numbers[right - 1];
	size_median++;
	return numbers[right - 1];
}

void InsertSort(int numbers[], int left, int right)
{
	for (int i = left + 1; i < right + 1; i++)
	{
		int temp = numbers[i],point,k;
		if (numbers[i] < numbers[i - 1])
		{
			point = left;
			for (; numbers[point] < temp; point++);
			for (k = i; k > point; k--)
				numbers[k] = numbers[k - 1];
			numbers[point] = temp;
		}
	}
}

void QuickSort(int numbers[],int left,int right)
{
	if (right - left < 5)
	{
		InsertSort(numbers, left, right);
		return;
	}
	else if (left < right)
	{
		int pivot = Median3(numbers,left, right);
		int Left = left, Right = right - 1;
		while (Left < Right)
		{
			while (Left < Right && numbers[++Left] < pivot);
			while (Left < Right && numbers[--Right] > pivot);
			swap(numbers[Left], numbers[Right]);
		}
		swap(numbers[Left], numbers[right - 1]);
		int Middle = Left;
		if (Middle != -1)
		{
			QuickSort(numbers,left, Middle - 1);
			QuickSort(numbers,  Middle +1,right);
		}
	}
}

void Print(int list[],int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}

int main()
{
	int numbers[100010], i,size_numbers=0;
	string temp;
	while (1)
	{
		cin >> temp;
		if (temp[0] == '#')
			break;
		numbers[size_numbers] = atoi(temp.c_str());//将字符串转化成整数
		size_numbers++;
	}
	QuickSort(numbers,0, size_numbers - 1);
	printf("After Sorting:\n");
	Print(numbers,size_numbers);
	printf("Median3 Value:\n");
	if (size_numbers > 5)
		Print(median, size_median);
	else
		printf("none\n");
}