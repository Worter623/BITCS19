#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Tree;

char PostOrder[100],InOrder[100];

struct Node{
	char data;
    Tree LeftChild,RightChild;
};

Tree Reduction(char postorder[],char inorder[],int i,int j,int n,int m){
    Tree a;
    a=(Tree)malloc(sizeof(struct Node));
    a->data=postorder[j];
    int k=n;
    while(inorder[k]!=postorder[j])
        k++;
    if(inorder[n]==postorder[j])
        a->LeftChild=NULL;
    else
        a->LeftChild=Reduction(postorder,inorder,i,i+k-n-1,n,k-1);
    if(inorder[m]==postorder[j])
        a->RightChild=NULL;
    else
        a->RightChild=Reduction(postorder,inorder,i+k-n,j-1,k+1,m);
    return a;
}

int LevelOrder(Tree a, int level){
    if(!a||level<0)
        return 0;
    if(!level){
        printf("%c",a->data);
        return 1;
    }
    return LevelOrder(a->LeftChild,level-1)+LevelOrder(a->RightChild,level-1);
}

int main(){
    scanf("%s",&InOrder);
    scanf("%s",&PostOrder);
    int i,length=strlen(InOrder);
    Tree a=Reduction(PostOrder,InOrder,0,length-1,0,length-1);
    for(i=0;;i++){
        if(!LevelOrder(a,i))
            break;
    }
    printf("\n");
}