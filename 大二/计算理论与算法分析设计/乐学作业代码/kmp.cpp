#include <iostream>  
#include <string> 
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int pf[100000];

void ComputePrefixFunction(int m,char pattern[])
{
	pf[1] = 0; 
	int k = 0;
	for (int q = 2; q <= m ; q++)
	{
		while (k > 0 && pattern[k] != pattern[q - 1])
			k = pf[k];
		if (pattern[k] == pattern[q - 1])
			k++;
		pf[q] = k;
	}
}

int KMP(char text[], int n, int m, char pattern[])
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		while (count > 0 && pattern[count] != text[i-1])
			count = pf[count];
		if (pattern[count] == text[i-1])
			count++;
		if (count == m)
			return i - m;
	}
	return -1;
}

int main()
{
	memset(pf, 0, sizeof(pf));
	char text[100000], pattern[100000];
	cin >> text >> pattern;
	int n = strlen(text), m = strlen(pattern);
	ComputePrefixFunction(m, pattern);
	cout << KMP(text, n, m, pattern)<<endl;
}
