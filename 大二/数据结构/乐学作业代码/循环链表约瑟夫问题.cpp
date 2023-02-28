#include <stdio.h>  
#include <stdlib.h>  
typedef int element_type;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node 
{  element_type element;  
   Position next;  
}; 

void setlist(List head,element_type n)  
{     
    Position p;  
    for(element_type temp=n;temp>1;temp--)
    {
	   	p=(Position)malloc(sizeof(struct Node));  
        p->element=temp;  
        p->next=head->next;  
        head->next=p; 
    }
}  
int main( )  
{   element_type n,k,m,tem,count=1;  
    List head; 
    Position temp,x;
    scanf("%d,%d,%d",&n,&k,&m); 
    if(n<1||m<1||k<1)
    	printf("n,m,k must bigger than 0.");
    else
    {
    	if(k>n)
    		printf("k should not bigger than n.");
    	else
    	{
    		head=(Position)malloc(sizeof(struct Node));  
   			head->element=1;  
    		head->next=head;  
    		setlist(head,n);
    		temp=head;
    		for(int i=0;i<k-1;i++)
    			temp=temp->next;
			while(temp!=temp->next)
			{
				for(tem=1;tem<m;tem++)
				{
					x=temp;
					temp=temp->next;
				}
				printf("%d",temp->element);
				count++;
				if(count==11)
				{
					printf("\n");
					count=1;
				}
				else
					printf(" ");
				x->next=temp->next;
				temp=temp->next;
			}
			printf("%d",temp->element);
		}
	}
    if(count!=11)	printf("\n");  
    return 0;
}  


