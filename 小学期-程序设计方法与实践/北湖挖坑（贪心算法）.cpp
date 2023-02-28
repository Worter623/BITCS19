#include<stdio.h>  
#include<string.h>  

int main()  
{/*获取每列深度，需要挖去的部分单独取出并倒置，为实现最后一列全部计算且防止re将第n+1列深度设为0*/ 
    long long int n,h,column_height[100003],reverse_depth[100003],interval=0;  
    scanf("%lld %lld\n",&n,&h);  
    for(long long int i=0;i<n;i++)   
		scanf("%lld",&column_height[i]); 
	for(long long int i=0;i<n;i++)
		reverse_depth[i] = h-column_height[n-1-i];
	reverse_depth[n]=0;
 	/*左边一列若比右边高，则答案+=左右高度差*/
	for(long long int i=0;i<n;i++)
		if(reverse_depth[i]>reverse_depth[i+1])
			interval+=reverse_depth[i]-reverse_depth[i+1];
	printf("%lld\n",interval);
}
