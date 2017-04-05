#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//宏定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACKEMPTY -3

#define LT(a,b) ((a) < (b))
#define N = 100
//状态的定义
typedef int Status;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
typedef struct stack{
    LinkList top;
}STACK;
//初始化栈
void InitStack(STACK &S){
    S.top = NULL;
}
//入栈的操作
void Push(STACK &S,ElemType e){
    LinkList p;
    p = (LinkList)malloc(sizeof(LNode));
    if(!p)
        exit(OVERFLOW);
    p -> data = e;
    p -> next = S.top;
    S.top = p;
}
//出栈
void Pop(STACK &S,ElemType *e){
    LinkList p;
    *e = S.top -> data;
    p = S.top;
    S.top = S.top -> next;
}
int  main()
{
    
    STACK S;
    InitStack( S);
    Push(S, 3);
    Push(S, 4);
    ElemType e;
    Pop(S,&e);
    cout<<"Pop elem:"<<e;
    return 0;
}
