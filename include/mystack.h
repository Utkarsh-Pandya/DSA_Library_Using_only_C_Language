#ifndef __mystack__
#define __mystack__ 69
#include<myconst.h>
#include<myerr.h>
typedef struct __stack_node{
void *ptr;
struct __stack_node *next;
}StackNode;
typedef struct __stack{
StackNode *top;
int elementSize;
int size;
}Stack;
void initStack(Stack *stack,int elementSize,int *successful,int *error);
void push(Stack *stack,void *ptr,int *successful,int *error);
void pop(Stack *stack,void *ptr,int *successful,int *error);
int isEmpty(Stack *stack,int *successful,int *error);
void clearStack(Stack *stack,int *successful,int *error);
#endif