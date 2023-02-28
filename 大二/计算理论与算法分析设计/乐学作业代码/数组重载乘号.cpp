#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input1[20002], input2[20002];
int op1[20002],op2[20002], result[20002 * 2 + 10];

int main()
{
	scanf("%s", &input1);
	scanf("%s", &input2);
	int length1 = strlen(input1),length2 = strlen(input2);
	if (input1[0]=='0' || input2[0] == '0')
		printf("0\n");
	else
	{
		for (int i = 0; i < length1; i++)
			op1[i] = input1[length1-1-i] - '0';
		for (int i = 0; i < length2; i++)
			op2[i] = input2[length2-1-i] - '0';
		for (int i = 0; i < length1; i++)
		{//ох*
			for (int j = 0; j < length2; j++)
				result[i + j]+= op1[i] * op2[j];
		}
		for (int i = 0; i < 40004; i++)
		{
			if (result[i] >= 10)
			{
				result[i + 1] += result[i] / 10;
				result[i] %= 10;
			}
		}
		int digit = 40002;
		for (; digit >= 0; digit--)
		{
			if (result[digit] == 0)	continue;
			else break;
		}
		for (; digit >= 0; digit--)
			printf("%d", result[digit]);
		printf("\n");
	}
}
