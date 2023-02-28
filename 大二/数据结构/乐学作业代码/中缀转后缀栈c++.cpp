#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

typedef char element_type;

stack <element_type> fomulation;

int main()
{
	int i,test_case;
	element_type temp,t,ch;
	scanf("%d",&test_case);
	for(i=0;i<test_case;i++){
		scanf("%c",&ch);
		while(1){
			scanf("%c",&temp);
			if(temp=='#')	break;
			else{
				if(temp==')'){
					while(fomulation.top()!='('){
						printf("%c",fomulation.top());
						fomulation.pop();
					}				
					fomulation.pop();//弹出左括号
				}
				else {
					if(temp=='('||temp=='^')
						fomulation.push(temp);
					else{
						if(temp=='*'||temp=='/'){
							while(!fomulation.empty()){
								t=fomulation.top();
								if(t=='^'||t=='*'||t=='/'){
									printf("%c",fomulation.top());
									fomulation.pop();					
								}
								else
									break;
							}
							fomulation.push(temp);
						}
						else{
							if(temp=='+'||temp=='-'){
								while(!fomulation.empty()){
									t=fomulation.top();
									if(t=='^'||t=='/'||t=='*'||t=='+'||t=='-'){
										printf("%c",fomulation.top());
										fomulation.pop();											
									}
									else
										break;
								}
								fomulation.push(temp);
							}
							else
								printf("%c",temp);
						}	
					}
				}
			}
		}
		while(!fomulation.empty())
		{
			printf("%c",fomulation.top());
			fomulation.pop();			
		}
		printf("\n");
	}
}
