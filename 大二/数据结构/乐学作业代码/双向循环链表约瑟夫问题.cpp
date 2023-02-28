#include <stdio.h>  
#include <stdlib.h>  
typedef int element_type;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node 
{  element_type element;  
   Position previous; 
   Position next;  
}; 

void setlist(List head,element_type n)  
{     
    Position p,tem_p=head; 
    for(element_type temp=n;temp>1;temp--)
    {
	   	p=(Position)malloc(sizeof(struct Node));  
        p->element=temp;
		p->previous=head;  
        p->next=head->next;  
        head->next=p; 
        tem_p->previous=p;
        tem_p=p;
    }
}  
void Delete(Position p)
{
	p->previous->next=p->next;
	p->next->previous=p->previous;
}
int main( )  
{   element_type n,k,m;  
    List head; 
    Position temp,temp2,x,x2;
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
			head->previous=head; 
    		setlist(head,n);
    		temp=head;
    		while(temp->element!=k)
    			temp=temp->next;
    		temp2=temp;
			while(n)
			{
				x=temp;x2=temp2;
				for(int i=1;i<m;i++)
				{					
					x=x->next;
					x2=x2->previous;
				}
				temp=x->next;temp2=x2->previous;
				if(x->element!=x2->element)
				{
					n-=2;
					printf("%d-%d,",x->element,x2->element);
					Delete(x);Delete(x2);
				}	
				else
				{
					n-=1;
					printf("%d,",x->element);
					Delete(x);
				}	
			}
		}
	}
    printf("\n");  
    return 0;
}  


