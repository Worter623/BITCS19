#include <stdio.h>  
#include <stdlib.h>  
typedef int element_type;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node 
{  char bracket; 
   Position next; 
   Position previous; 
}; 

void push(List stack,char temp)
{
	List head=stack;
	Position p=(Position)malloc(sizeof(struct Node));
	p->bracket=temp;
	p->next=NULL;
	p->previous=stack;
	head->next=p;
}

int check(List stack,char temp)
{
	if(temp==')')
		if(stack->bracket=='(')
			return 1;	
	if(temp==']')
		if(stack->bracket=='[')
			return 1;		
	return 0;	
}

int main( )  
{   
    List stack; 
    stack=(List)malloc(sizeof(struct Node));
    stack->bracket=',';
    stack->next=NULL;
    stack->previous=NULL;
    char temp;
    while(1)
	{
		scanf("%c",&temp); 
		if(temp=='\n')
			break;
		if(temp=='('||temp=='[')
		{
			push(stack,temp);
			stack=stack->next;
		}			
		else
		{
			if(temp==')'||temp==']')
				if(check(stack,temp)==0)
				{
					printf("Match false!\n");
					return 0;		
				}
				else
				{
					stack=stack->previous;
					stack->next=NULL;
				}
			else
				continue;
		}
	}
	printf("Match succeed!\n");
}  


