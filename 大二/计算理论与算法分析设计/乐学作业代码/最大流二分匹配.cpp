#include <iostream>  
#include <string.h> 
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Pupil
{
	int height;
	char sex;
	string music, sport;
};
int visit[502];
vector<int> graph[505];

int BFS(int start, int end) {
	queue <int> q;
	memset(visit, 0, sizeof(visit));
	int vertex[502];
	q.push(start);
	visit[start] = 1;
	int temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		int size = graph[temp].size();
		for (int k = 0; k < size; k++)
			if (visit[graph[temp][k]] == 0) {
				q.push(graph[temp][k]);
				visit[graph[temp][k]] = 1;
				vertex[graph[temp][k]] = temp;
			}
	}
	if (visit[end] == 0)
		return 0;
	for (int i = end; i > 0;) {
		int origin = i;
		i = vertex[i];
		graph[origin].push_back(i);
		std::vector<int>::iterator pos;
		pos = find(graph[i].begin(), graph[i].end(), origin);
		if (pos != graph[i].end())
			graph[i].erase(pos);
	}
	//for (int i = 0; i <= end; i++)
	//{
	//	for (int j = 0; j < graph[i].size(); j++)
	//		cout << graph[i][j];
	//	cout << endl;
	//}
	//cout << "!!!!!!" << endl;
	return 1;
}

int MaximumFlowEK(int start, int end) {
	int total = 0;
	while (BFS(start, end) != 0)
		total++;
	return total;
}

void input(int n) {
	queue <struct Pupil> male;
	Pupil temp, female[505];
	int femalenumber = 0;
	for (int i = 0; i < n; i++)
	{//input
		cin >> temp.height >> temp.sex >> temp.music >> temp.sport;
		if (temp.sex == 'M')
			male.push(temp);
		else
			female[femalenumber++] = temp;
	}
	int count = 0, malesize = male.size();
	Pupil current;//finally we should have count+1==malesize
	while (!male.empty()) {//creating graph step1
		current = male.front();
		male.pop();
		count++;
		for (int i = 0; i < femalenumber; i++)
			if (abs(current.height - female[i].height) <= 40)
				if (current.music == female[i].music && current.sport != female[i].sport)
					graph[count].push_back(malesize + i + 1);
	}//creating graph step2
	for (int i = 1; i <= malesize; i++)
		graph[0].push_back(i);
	for (int i = malesize + 1; i <= malesize + femalenumber; i++)
		graph[i].push_back(malesize + femalenumber + 1);
}

int main() {
	int test_case, n, ans;
	cin >> test_case;
	while (test_case--) {//initialize
		cin >> n;
		for (int i = 0; i < n+1; i++)
			graph[i].clear();
		input(n);//maximum flow
		ans = MaximumFlowEK(0, n+1);
		cout << n - ans << endl;
	}
}
