#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void swap(long long int *number1,long long int *number2)
{
	long long int tempor=*number1;
	*number1=*number2;
	*number2=tempor;
}
void adjustleft(long long int left[],long long int sizel,long long int currentnode)
{//调整大根堆 下沉 
	long long int rlargest=currentnode,llargest=currentnode,leftc,rightc,largest;
	leftc=2*currentnode+1;
	rightc=2*currentnode+2;
	if(rightc<sizel&&left[rightc]>left[currentnode])
		rlargest=rightc;
	if(leftc<sizel&&left[leftc]>left[currentnode])
		llargest=leftc;	
	largest=(left[rlargest]>left[llargest])?rlargest:llargest;	
	if(largest!=currentnode)
	{
		swap(&left[largest],&left[currentnode]);
		adjustleft(left,sizel,largest);
	}
}
void floatleft(long long int left[],long long int sizel,long long int currentnode)
{//大根堆上浮  
	long long int father=(currentnode-1)/2,largest;
	if(father>=0&&left[father]<left[currentnode])
		largest=father;
	else
		largest=currentnode;
	if(largest!=currentnode)
	{
		swap(&left[largest],&left[currentnode]);
		floatleft(left,sizel,largest);
	}
}
void deleteleft(long long int left[],long long int sizel)
{//删除大根堆中的最大元素（首项） 
	swap(&left[0],&left[sizel]);
	adjustleft(left,sizel,0);
}
void adjustright(long long int right[],long long int sizer,long long int currentnode)
{//调整小根堆 下沉 
	long long int minimum,leftc,rightc,rminimum=currentnode,lminimum=currentnode;
	leftc=2*currentnode+1;
	rightc=2*currentnode+2;
	if(rightc<sizer&&right[rightc]<right[currentnode])
		rminimum=rightc;
	if(leftc<sizer&&right[leftc]<right[currentnode])
		lminimum=leftc;
	minimum=(right[rminimum]<right[lminimum])?rminimum:lminimum;
	if(minimum!=currentnode)
	{
		swap(&right[minimum],&right[currentnode]);
		adjustright(right,sizer,minimum);
	}
}
void floatright(long long int right[],long long int sizer,long long int currentnode)
{//小根堆上浮  
	long long int father=(currentnode-1)/2,minimum;
	if(father>=0&&right[father]>right[currentnode])
		minimum=father;
	else
		minimum=currentnode;
	if(minimum!=currentnode)
	{
		swap(&right[minimum],&right[currentnode]);
		floatright(right,sizer,minimum);
	}
}
void deleteright(long long int right[],long long int sizer)
{//删除小根堆中的最小元素（首项） 
	swap(&right[0],&right[sizer]);
	adjustright(right,sizer,0);
}
long long int xleft[250003]={0},xright[250003]={0},yleft[250003]={0},yright[250003]={0};
int main()
{//曼哈顿距离最短：取所有点的中位数 
	long long int i,j,test_case,n;
	scanf("%lld\n",&test_case);
	for(i=0;i<test_case;i++)
	{
		printf("Case: %lld\n0.0000\n",i+1);
		scanf("%lld\n",&n);
		long long int xtemp,ytemp,xmid=0,ymid=0,xsize_left=0,xsize_right=0,ysize_left=0,ysize_right=0,
					xsum_right=0,xsum_left=0,ysum_left=0,ysum_right=0,xdistance=0,ydistance=0,distance=0;
		scanf("%lld %lld\n",&xmid,&ymid);
		for(j=1;j<n;j++)
		{
			scanf("%lld %lld",&xtemp,&ytemp);
			if(xtemp<xmid)
			{//放进大根堆后面  上浮使大根堆有序  
				xleft[xsize_left++]=xtemp;
				xsum_left+=xtemp;
				floatleft(xleft,xsize_left,xsize_left-1);
			}
			else
			{//放进小根堆后面  上浮使小根堆有序 
				xright[xsize_right++]=xtemp;
				xsum_right+=xtemp;
				floatright(xright,xsize_right,xsize_right-1);
			}
			if(xsize_left-xsize_right>1)
			{//更新中位数，将中位数放进较少的堆里，再从较多的堆里取堆顶作为新的中位数  删除堆顶 
				xright[xsize_right++]=xmid;
				xsum_right+=xmid;
				floatright(xright,xsize_right,xsize_right-1);
				xmid=xleft[0];
				xsum_left-=xleft[0];
				xsize_left--;
				deleteleft(xleft,xsize_left);
			}
			if(xsize_right-xsize_left>1)
			{
				xleft[xsize_left++]=xmid;
				xsum_left+=xmid;
				floatleft(xleft,xsize_left,xsize_left-1);
				xmid=xright[0];
				xsum_right-=xright[0];
				xsize_right--;
				deleteright(xright,xsize_right);
			}//对y，一模一样 
			if(ytemp<ymid)
			{
				yleft[ysize_left++]=ytemp;
				ysum_left+=ytemp;
				floatleft(yleft,ysize_left,ysize_left-1);
			}
			else
			{
				yright[ysize_right++]=ytemp;
				ysum_right+=ytemp;
				floatright(yright,ysize_right,ysize_right-1);
			}
			if(ysize_left-ysize_right>1)
			{
				yright[ysize_right++]=ymid;
				ysum_right+=ymid;
				floatright(yright,ysize_right,ysize_right-1);
				ymid=yleft[0];
				ysum_left-=yleft[0];
				ysize_left--;
				deleteleft(yleft,ysize_left);
			}
			if(ysize_right-ysize_left>1)
			{
				yleft[ysize_left++]=ymid;
				ysum_left+=ymid;
				floatleft(yleft,ysize_left,ysize_left-1);
				ymid=yright[0];
				ysum_right-=yright[0]; 
				ysize_right--;
				deleteright(yright,ysize_right);
			}//计算最小距离 每一次都打印
			xdistance=xmid*xsize_left-xsum_left+xsum_right-xmid*xsize_right;
			ydistance=ymid*ysize_left-ysum_left+ysum_right-ymid*ysize_right;
			distance=xdistance+ydistance;
			printf("%lld.0000\n",distance);
		}
	}
} 
