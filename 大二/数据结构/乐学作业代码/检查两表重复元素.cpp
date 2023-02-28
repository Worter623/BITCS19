#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node 
{  int number;
   char name[20];
   Position next;  
}; 

void setlist(List head,int n)  
{     
    Position p,temp_p=head;  
    for(int temp=0;temp<n;temp++)
    {
		p=(Position)malloc(sizeof(struct Node));  
	   	scanf("%d %s",&p->number,&p->name);
        p->next=NULL;
		temp_p->next=p;
		temp_p=p;
    }
}  
int Find(int x,char name[],List head)
{
	Position p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		if(x==p->number&&strcmp(name,p->name)==0)
			return 1;//若str1=str2返回0 
	}
	return 0;
}
int main( )  
{   int l1,l2,flag=0;
    List head1,head2; 
    scanf("%d",&l1); 
	head1=(Position)malloc(sizeof(struct Node)); 
    head1->next=NULL;  
    setlist(head1,l1);
    scanf("%d",&l2);
    if(l2==0)
    	printf("the LIST2 is NULL.\n");
    else
    {
    	head2=(Position)malloc(sizeof(struct Node)); 
    	head2->next=NULL;  
    	setlist(head2,l2);
    	Position temp=head2;
    	for(int i=0;i<l2;i++)
    	{
    		temp=temp->next;
			if(!Find(temp->number,temp->name,head1))//找得到并相同return 1，否则return0
			{
				printf("%8d %s is not in LIST1.\n",temp->number,temp->name);
				flag=1; 
			}
		}
		if(!flag)
			printf("the records of LIST2 are all in the LIST1.\n");
	}
	return 0;
}  


