#include <stdio.h>  
#include <stdlib.h>
#define maxdegree 10000
typedef int element_type;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node 
{  element_type max_power,coef[maxdegree];  
}; 

void zeropoly(List head,element_type n)
{
	element_type i;
	for(i=0;i<n;i++)
		head->coef[i]=0;
	head->max_power=0;
}

void setpoly(List head,element_type m)  
{         
	zeropoly(head,maxdegree);
    element_type x1,x2;
    for(element_type i=0;i<m;i++)
    {
	   	scanf("%d %d",&x1,&x2);
		if(head->max_power < x2)	
			head->max_power=x2;
		head->coef[x2]=x1;
    }
}  

void printpoly(List head)
{
	int flag=0;
	for(element_type i=0;i<head->max_power;i++)
		if(head->coef[i]!=0)
		{
			flag=1;
			printf("<%d,%d>,",head->coef[i],i);
		}
	if(flag==1)
		printf("<%d,%d>\n",head->coef[head->max_power],head->max_power);
	else
		printf("<0,0>\n");
}

void addpoly(List add1,List add2,List ans)
{
	ans->max_power=(add1->max_power > add2->max_power)?add1->max_power:add2->max_power;
	for(element_type i=ans->max_power;i>=0;i--)
		ans->coef[i]=add1->coef[i] + add2->coef[i];
}

int main( )  
{   element_type op,n1,n2,n3,max_d; 
    List poly1,poly2,poly3,polysum,polyans; 
    scanf("%d",&op); 
    if(op==0)	return 0;
    else
    {
    	poly1=(Position)malloc(sizeof(struct Node));
    	poly2=(Position)malloc(sizeof(struct Node));
    	poly3=(Position)malloc(sizeof(struct Node));
    	polysum=(Position)malloc(sizeof(struct Node));
    	polyans=(Position)malloc(sizeof(struct Node));
		scanf("%d",&n1);
    	setpoly(poly1,n1);
    	printpoly(poly1);
    	scanf("%d",&n2);
    	setpoly(poly2,n2);
    	printpoly(poly2);
    	max_d=(n1>n2)?n1:n2;
    	scanf("%d",&n3);
    	setpoly(poly3,n3);
    	printpoly(poly3);
    	zeropoly(polysum,max_d);
    	max_d=(max_d > n3)?max_d:n3;
    	zeropoly(polyans,max_d);
    	addpoly(poly1,poly2,polysum);
    	printpoly(polysum);
    	addpoly(polysum,poly3,polyans);
    	printpoly(polyans);
    	return 0;
	}
}  



