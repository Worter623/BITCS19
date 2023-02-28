#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE * );  
void change( int, int, NODE * );  
  
void output( NODE * head )  
{   int k=0;  
    printf("0.");  
    while ( head->next != NULL && k<50 )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
void change(int n,int m,NODE * head)
{
	NODE * p=head,* temp=NULL,* q=NULL;
	int upper=n,i=0,j,ans[52];
	while(upper&&i<50)
	{
		ans[i++]=(upper*=10);
		q=head->next;	
		for(j=0;j<i-1&&q!=NULL;)
		{//循环节发现，指回去就行 
			if(ans[j++]==upper)
			{				
				p->next=q;
				return;
			}
			q=q->next;
		}
		temp=(NODE *)malloc(sizeof(NODE));
		temp->data=upper/m;
		upper%=m;
		p->next=temp;
		p=temp;
		p->next=NULL;	
	}	
}
int main()  
{   int n, m;  
    NODE * head;
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

