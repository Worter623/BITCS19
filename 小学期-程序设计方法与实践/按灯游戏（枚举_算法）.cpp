#include<stdio.h>  
#include<string.h>  
char cinput[20][20];  
int input[20][20],map[20][20],press[20][20];  
  
long long int line(int n,int m);/*枚举第一行的2^m种可能*/  
long long int test(int n,int m);/*检查最后一行的灯是不是都关着*/  
void switches(int i,int j); /*按第i行第j列后周围共五盏灯的变化情况*/  
  
long long int line(int n,int m)  
{/*计算2^m*/  
    long long int possibilities=1<<17,result=999999999,minstep[1<<17];  
    for(int i=0;i<possibilities;i++)  
    {/*先模拟第一行，记录改变或不改变*/   
        int temp=i;  
        for(int j=1;j<m-1;j++)  
        {  
            press[1][j]=temp%2;  
            temp/=2;  
        }  
    /*每一次尝试之前初始化*/  
        for(int j=1;j<n;j++)  
            for(int k=1;k<m-1;k++)  
                map[j][k]=input[j][k];  
    /*调用test函数检验可不可行   每调用一次函数都会改变函数值 */  
        int k=test(n,m);/*函数返回值的设置  考虑step=0的特殊情况*/  
        if(k>=0)  
            minstep[i] = k;  
        else  
            minstep[i] = 9999999999;  
    }  
/*选出最小步数*/  
    for(int i=0;i<possibilities;i++)  
    {  
        result = (minstep[i]<result)?minstep[i]:result;  
    }  
    return result;  
}  
  
long long int test(int n,int m)  
{/*按开关*/  
    long long int step=0;  
    for(int i=1;i<n;i++)  
    {/*按第i行的开关*/  
        for(int j=1;j<m-1;j++)  
            if(press[i][j]==1)  
                {step++;switches(i,j);}  
        for(int j=1;j<m-1;j++)  
        {/*根据第i行灯的开关情况决定第i+1行按或不按*/  
            if(map[i][j]==1)  
                press[i+1][j]=1;  
            else  
                press[i+1][j]=0;        
        }     
    }  
    /*检验最后一行的灯是不是关着，是就返回步数*/      
    int sum=0;  
    for(int i=1;i<m-1;i++)  
        sum+=map[n-1][i];  
    if(sum==0)  return step;  
    if(sum>0)    return -1;  
}  
  
void switches(int i,int j)  
{  
    map[i][j]=(map[i][j]+1)%2;  
    map[i+1][j]=(map[i+1][j]+1)%2;    
    map[i-1][j]=(map[i-1][j]+1)%2;    
    map[i][j+1]=(map[i][j+1]+1)%2;    
    map[i][j-1]=(map[i][j-1]+1)%2;  
}  
  
int main()  
{  
    int n,m;  
    scanf("%d %d\n",&n,&m);  
    m+=2;n++;  
    for(int i=1;i<n;i++)  
        for(int j=1;j<m;j++)  
        {
			scanf("%c",&cinput[i][j]); 
			input[i][j]=cinput[i][j]-'0';	   	
		} 
    printf("%lld\n",line(n,m));  
}  
