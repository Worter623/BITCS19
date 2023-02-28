#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Bail;

struct Node{
	int code;
	int orderid;
	float price;
	int quantity;
	char type;
	Bail next,previous;
};

Bail bail_system;
int system_size=0;

int read_and_return_code(){
	char code_char[5];
	scanf("%s",code_char);
	int code_int=0,i;
	for(i=0;i<4;i++)
		code_int=(code_char[i]-'0')+code_int*10;
	return code_int;
}

void search_code(Bail bail_system, char bail_type,int code_to_search){
	Bail head=bail_system;
	int flag1=999999;
	while(head->next!=NULL){
		head=head->next;
		if(head->code==code_to_search&&head->type==bail_type&&head->quantity>0)
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",head->orderid,head->code,head->price,head->quantity,bail_type);
	}
}

Bail read_and_return_for1(){
	char temp;
	int code_int=0,quantity_int=0,i;
	float price_int=0.0;
	temp=getchar();
	for(i=0;i<4;i++){
		scanf("%c",&temp);
		code_int=(temp-'0')+code_int*10;
	}	
	Bail p=(Bail)malloc(sizeof(struct Node));
	p->code=code_int;
	temp=getchar();
	temp=getchar();
	while(temp!=' '){
		price_int=(temp-'0')+price_int*10;
		temp=getchar();
	}//temp=' '
	p->price=price_int;
	temp=getchar();
	while(temp!=' '){
		quantity_int=(temp-'0')+quantity_int*10;
		temp=getchar();
	}	
	p->orderid=system_size;
	p->quantity=quantity_int;
	scanf("%c",&p->type);
	temp=getchar();//\n	
	return p;
}

void delete_bail(Bail p){
	Bail head=p;
	Bail to_delete=head->previous;
	to_delete->next=head->next;
	if(head->next!=NULL)
		head->next->previous=to_delete;
}

void insert(Bail p){
	Bail head=bail_system,insert_after=bail_system;
	while(head->next!=NULL){
		head=head->next;
		if(p->type=='b'){
			if(head->type=='b'&&p->price<=head->price)
				insert_after=head;			
		}
		else{
			if(head->type=='s'&&p->price>=head->price)
				insert_after=head;			
		}
	}
	p->previous=insert_after;
	p->next=insert_after->next;
	if(insert_after->next!=NULL)
		insert_after->next->previous=p;
	insert_after->next=p;
}

void manage_to_deal(Bail input){
	Bail head=bail_system;
	float highestP=0.0,lowestP=9999999.9;
	int flag=-1;
	Bail this_order;
	while(head->next!=NULL){//要卖，先sellorder
		head=head->next;		
		if(head->code==input->code&&head->type=='b'&&input->type=='s'&&head->price>=input->price&&head->quantity>0)
			if(head->price>highestP){
				highestP=head->price;
				flag=1;
				this_order=head;
			}//要买，先buyorder
		if(head->code==input->code&&head->type=='s'&&input->type=='b'&&head->price<=input->price&&head->quantity>0)
			if(head->price<lowestP){
				lowestP=head->price;
				flag=1;
				this_order=head;
			}
	}
	if(flag!=-1){
		int deal_number=min(input->quantity,this_order->quantity);
		float deal_price=(input->price+this_order->price)/2;
		if(this_order->type=='b')
			printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",deal_price,deal_number,input->orderid,this_order->orderid);
		else
			printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",deal_price,deal_number,input->orderid,this_order->orderid);
		if(input->quantity>=this_order->quantity){//原来的单不剩，新单没交易完
			Bail change_order=input;
			change_order->quantity=input->quantity-this_order->quantity;
			delete_bail(this_order);
			delete_bail(input);
			insert(change_order);
			if(change_order->quantity!=0)
				manage_to_deal(change_order);
		}
		else{//原来的单还剩余，保留单不变，改quantity就行	
			this_order->quantity=this_order->quantity-input->quantity;	
			delete_bail(input);	
		}	
	}
}

void function_apply(){
	Bail p= read_and_return_for1();
	insert(p);
	printf("orderid: %04d\n",system_size);
	manage_to_deal(p);
}

void function_search(){
	int code_to_search=read_and_return_code();
	printf("buy orders:\n");
	search_code(bail_system,'b',code_to_search);
	printf("sell orders:\n");
	search_code(bail_system,'s',code_to_search);
}

void search_bail(Bail bail_system, int bail_to_cancel){
	Bail head=bail_system;
	int found=0;
	while(head->next!=NULL){
		head=head->next;
		if(head->orderid==bail_to_cancel){
			found=1;
			printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",head->orderid,head->code,head->price,head->quantity,head->type);
			delete_bail(head);
			break;
		}
	}
	if(found==0)
		printf("not found\n");
}

void function_cancel(){
	int bail_to_cancel=read_and_return_code();
	if(bail_to_cancel>system_size)
		printf("not found\n");
	else
		search_bail(bail_system,bail_to_cancel);
}

int main(){
	int function_type,flag=0;
	bail_system=(Bail)malloc(sizeof(struct Node));
	bail_system->next=NULL;
	bail_system->previous=NULL;
	bail_system->orderid=0;
	while(!flag){
		scanf("%d",&function_type);
		switch(function_type){
			case 0:{
				flag=1;
				break;
			}			
			case 1:{
				system_size++;
				function_apply();
				break;				
			}
			case 2:{
				function_search();
				break;				
			}
			case 3:{
				function_cancel();
				break;				
			}
			default:
				break;
		}
	}
}
