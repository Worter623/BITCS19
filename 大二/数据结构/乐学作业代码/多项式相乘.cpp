#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
void multiplication(NODE * head1, NODE * head2, NODE * head3 )
{
	NODE * p1,* p2=head2,*p3;
	int flag=0,x1,x2;
	while(p2->next!=NULL)
	{
		p1=head1;
		p2=p2->next;
		if(p2->coef==0&&flag==1)continue;
		p3=head3;
		while(p1->next!=NULL)
		{
			p1=p1->next;
			x1=p1->exp+p2->exp;
			x2=p1->coef*p2->coef;
			if (x2==0&&flag==1)continue;
			NODE * tp,* temp;
			while(p3!=NULL)
			{
				tp=p3;
				p3=p3->next;
				if(p3==NULL)
				{
					temp=(NODE*)malloc(sizeof(NODE));
					if(x2==0&&flag==0)
					{
						flag=1;
						temp->exp=0;
					}
					else
						temp->exp=x1;
					temp->coef=x2;
					temp->next=p3;
					tp->next=temp;
					p3=tp;
					break;
				}
				if(p3->exp<x1)continue;
				else 
				{
					if(p3->exp==x1)
					{
						p3->coef += x2;
						if(p3->coef==0&&x1!=0)
							tp->next=p3->next;
						p3=tp;
						break;
					}
					else
					{
						temp=(NODE *)malloc(sizeof(NODE));
						if(x2==0&&flag==0)
						{
							flag=1;temp->exp=0;
						}
						else
							temp->exp=x1;
						temp->coef=p1->coef*p2->coef;
						temp->next=p3;
						tp->next=temp;
						p3=tp;
						break;
					}
				}
			}
		}
	}		
} 
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  



