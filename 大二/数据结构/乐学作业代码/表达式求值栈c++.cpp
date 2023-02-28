#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

stack <char> fomulation;
stack <int> number;
char expression[10000]; 

int get_place(char op){
	int place=0;
	switch(op){
		case '+':
			place=0;break;
		case '-':
			place=1;break;
		case '*':
			place=2;break;
		case '/':
			place=3;break;
		case '(':
			place=4;break;
		case ')':
			place=5;break;
		case '#':
			place=6;break;
		case '^':
			place=7;break;
		case '%':
			place=8;break;
		default:
			break;
	}
	return place;
}

char get_priority(char op1, char op2){
	const char priority[9][9]={
		{'>','>','<','<','<','>','>','<','<'},    
		{'>','>','<','<','<','>','>','<','<'},  
		{'>','>','>','>','<','>','>','<','>'},   
		{'>','>','>','>','<','>','>','<','>'},  
		{'<','<','<','<','<','=',' ','<','<'},    
		{'>','>','>','>',' ','>','>','>','>'},    
		{'<','<','<','<','<',' ','=','<','<'},    
		{'>','>','>','>','<','>','>','<','>'}, 
		{'>','>','>','>','<','>','>','<','>'},
	};
	int row=get_place(op1),column=get_place(op2);
	return priority[row][column];
}

int calculate(int number2, char op, int number1){
	switch(op){
		case '+':
			return number2+number1;
		case '-':
			return number2-number1;
		case '*':
			return number2*number1;
		case '/':
			if(number1==0){
				printf("Divide 0.\n");
				return 0x3f3f3f3f;
			}
			else
				return number2/number1;
		case '^':
			if(number1>=0)
				return pow(number2,number1);
			else{
				printf("error.\n");
				return 0x3f3f3f3f;
			}
		case '%':
			return number2%number1;
		default:
			printf("error.\n");
			return 0x3f3f3f3f;
	}
}

bool judge(char temp){
	if(temp>='0'&&temp<='9')
		return false;
	int k=get_place(temp);
	if(k>=0&&k<=3)
		return true;
	if(k==7||k==8)
		return true;
	return	false;
}

int get_ans(char expression[]){
	int flag=0,count=0,left_bracket=0,p=0;
	while (expression[count]!='#'||fomulation.top()!='#'){
		if(expression[count]>='0'&&expression[count]<='9'){
			if(left_bracket==0&&flag==1){
				int temp_number = number.top();
				number.pop();
				number.push(temp_number*10+(expression[count]-'0'));
				flag=1;
			}
			else{
				number.push(expression[count]-'0');
				flag++;
			}
			count++;
			left_bracket=0;
		}
		else{
			flag=0;
			if(p==1){
				int opp=-number.top();
				number.pop();
				number.push(opp);
				p=0;
			}
			if(left_bracket==1){
				if(judge(expression[count])){
					printf("error.\n");
					return 0x3f3f3f3f;
				}
			}
			if(expression[count]=='('){
				left_bracket=1;
				if(expression[count+1]=='-'&&expression[count+2]>='0'&&expression[count+2]<='9'){
					left_bracket=2;
					p=1;
					count+=2;
					fomulation.push('(');
					continue;
				}
			}
			else
				left_bracket=2;
			switch(get_priority(fomulation.top(),expression[count])){
				case '<':{
					if(count==0&&expression[count]=='-')
	                    p=1;
					else
						fomulation.push(expression[count]);
					count++;
					break;
				}
				case '=':{
					fomulation.pop();
					count++;			
					break;
				}
				case '>':{
					if(expression[count]=='-') {  
                            char temp_char=expression[count-1];
							if(temp_char=='('||temp_char=='*'||temp_char=='/'||temp_char=='%'||temp_char=='+'||temp_char=='-') {   
                                count++;  
                                p=1;  
                                break;  
                            }  
                        } 
					char op = fomulation.top();
					fomulation.pop();
					int number1=number.top();
					number.pop();
					if(number.empty()){
						printf("error.\n");
						return 0x3f3f3f3f;
					}
					int number2=number.top();
					number.pop();
					if(p==1){
						int opp=-number.top();
						number.pop();
						number.push(opp);
						p=0;
					}
					number.push(calculate(number2,op,number1));					
					break;
				}
				case ' ':{
					printf("error.\n");
					return 0x3f3f3f3f;
				}
			}
		}
	}
	int res=number.top();
	number.pop();
	if(!number.empty()){
		printf("error.\n");
		return 0x3f3f3f3f;
	}	
	return res;
}

bool first_judge(char expression[], int lenth){
	int k,count,t;
	for(k=0;k<=lenth;k++){
		count=k;
		t=0;
		for(int i=0;i<3;i++){
			if(judge(expression[count])){
				count++;t++;
			}
		}
		if(t>2)
			return true;
		return false;		
	}
}

int main()
{
	int i,test_case;
	scanf("%d\n",&test_case);
	for(i=0;i<test_case;i++){
		while(!fomulation.empty())
			fomulation.pop();
		while(!number.empty())
			number.pop();
		fomulation.push('#');
		scanf("%s",&expression);
		strcat(expression,"#");
		if(first_judge(expression,strlen(expression)-3))
			printf("error.\n");
		else{
			int ans=get_ans(expression);
			if(ans!=0x3f3f3f3f)
				printf("%d\n",ans);	
		}
	}
}
