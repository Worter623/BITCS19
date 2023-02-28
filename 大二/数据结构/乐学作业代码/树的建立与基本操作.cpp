#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char input[100],data[100];
    scanf("%s",&input);
    int i,j,length,count=0,degree[100],depth=-1,max=0,DataCount[100]={0},NodeDegree[100]={0};
    length=strlen(input);
    for(i=0;i<length;i++){//建立树：计算每个节点的深度 存入degree数组，将每个节点的内容保存到data数组
        if(input[i]=='(')
            depth++;
        else if(input[i]==')')
            depth--;
        else if(input[i]==',')
            continue;
        else{
            data[count]=input[i];
            degree[count]=depth;
            count++;
        }
    }
    for(i=0;i<count;i++){//遍历树的每一个节点，打印树并且计算每个节点的度存进NodeDegree数组，DataCount数组记录度为i的节点有几个
        for(j=0;j<degree[i];j++)
            printf("    ");
        printf("%c\n",data[i]);
        for(j=i+1;j<count;j++){
            if(degree[i]==degree[j])
                break;
            if(degree[i]+1==degree[j])
                NodeDegree[i]++;
        }
        DataCount[NodeDegree[i]]++;
        if(NodeDegree[i]>max)
            max=NodeDegree[i];
    }
    printf("Degree of tree: %d\n",max);
    for(i=0;i<max+1;i++)
        printf("Number of nodes of degree %d: %d\n",i,DataCount[i]);
}