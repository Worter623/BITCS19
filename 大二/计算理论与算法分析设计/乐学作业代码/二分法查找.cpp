#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int n, k;
double CableLength[100002],sum=0;

bool Check(double CurrentLength)
{
	int CableNumber = 0;
	for (int i = 0; i < n; i++)
		CableNumber += (int)( CableLength[i] / CurrentLength);
	if (CableNumber >= k)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &CableLength[i]);
		sum += CableLength[i];
	}
	double left = 0.00, right = sum / k,middle;
	while (right - left > 0.001)
	{
		middle = (left + right) / 2.00;
		if (Check(middle))	left = middle;
		else right = middle;
	}
	//printf("%.2f\n", middle);
	printf("%.2f\n", floor(right * 100) / 100);//why!!!555
}