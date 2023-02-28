#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Dot
{
	double x, y;
};
Dot dot[100002];
int z[100002];

bool cmpy(const int& a, const int& b)
{
	return dot[a].y < dot[b].y;
}

double CalculateDistance(const Dot& a, const Dot& b)
{
	return sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
}

double solve(int left, int right)
{
	if (left == right)
		return 2e9;
	int mid = (left + right) / 2; 
	double d1 = solve(left, mid); 
	double d2 = solve(mid + 1, right); 
	double d = min(d1, d2);
	int count = 1;
	z[0] = mid; 
	for (int i = mid + 1; i <= right; i++)
	{
		if (dot[i].x - dot[mid].x > d)
			continue;
		z[count++] = i;
	}
	for (int i = mid - 1; i >= left; i--)
	{
		if (dot[mid].x - dot[i].x > d)
			continue;
		z[count++] = i;
	}
	sort(z, z + count, cmpy);
	for (int i = 0; i < count - 1; i++)
		for (int j = i +1; j < count && dot[z[j]].y - dot[z[i]].y < d; j++)
			d = min(d, CalculateDistance(dot[z[j]], dot[z[i]]));
	return d;
}

bool cmpx(const Dot& a, const Dot& b)
{
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}

int main()
{
	int n;
	double ans;
	cin >> n;
	while (n != 0)
	{
		memset(dot, 0, sizeof(dot));
		memset(z, 0, sizeof(z));
		for (int i = 0; i < n; i++)
			cin >> dot[i].x >> dot[i].y;
		sort(dot, dot + n, cmpx);//algorithmÖÐµÄsortº¯Êý

		ans = solve(0, n - 1) / 2;
		printf("%.2f\n", ans);
		cin >> n;
	}
}
