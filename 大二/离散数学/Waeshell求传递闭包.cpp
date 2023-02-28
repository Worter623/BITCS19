#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int main()
{
	int i, j, k, elements[100], sum = 0;
	int transfer[100][100];
	while (scanf("%d", &elements[sum++]) != EOF);
	int* p = elements;
	int rows = sqrt(sum);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < rows; j++)
			transfer[i][j] = p[j];
		p += rows;
	}
	for (k = 0; k < rows; k++)
		for (i = 0; i < rows; i++)
			for (j = 0; j < rows; j++)
				transfer[i][j] = transfer[i][j] || (transfer[i][k] && transfer[k][j]);
	for (i = 0; i < rows; i++)
		for (j = 0; j < rows; j++)
		{
			if (j == rows - 1)
				printf("%d\n", transfer[i][j]);
			else
				printf("%d ", transfer[i][j]);
		}
}