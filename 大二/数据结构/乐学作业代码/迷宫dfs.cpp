#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
using namespace std;

struct Cordinate
{
    int x, y, step;
}temp[10003], ans[10003];

int map[102][102], visit[102][102];

void dfs(int step, int x, int y, int n)
{
    int i, move[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
    if (x == n - 1 && y == n - 1)
    {//if搜到结果  
        if (step < 1000010)
        {
            ans[0].x = ans[0].y = step;
            for (i = 1; i < step + 1; i++)
                ans[i] = temp[i - 1];
            return;
        }
    }
    for (i = 0; i < 4; i++)
    { //对当前状态   
        int tempx, tempy;
        tempx = x + move[i][0];
        tempy = y + move[i][1];
        if (tempx >= 0 && tempx < n && tempy >= 0 && tempy < n && visit[tempx][tempy] == 0 && map[tempx][tempy] == 0)
        {
            visit[tempx][tempy] = 1;
            temp[step].x = tempx;
            temp[step].y = tempy;
            dfs(step + 1, tempx, tempy, n);
            visit[tempx][tempy] = 0;
        }
    }
}

int main()
{
    int n, i, j;
    char eater;
    scanf("%d%d", &n, &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            if (j != n - 1)
                scanf("%c", &eater);
        }
        if (i != n - 1)
            scanf("%c", &eater);
    }
    memset(visit, 0, sizeof(visit));
    visit[0][0] = 1;
    ans[0].x = ans[0].y = -1;
    dfs(0, 0, 0, n);
    if (ans[0].x == -1)
        printf("There is no solution!\n");
    else
    {
        printf("<1,1> ");
        for (i = 1; i < ans[0].x + 1; i++)
            printf("<%d,%d> ", ans[i].x + 1, ans[i].y + 1);
        printf("\n");
    }
}