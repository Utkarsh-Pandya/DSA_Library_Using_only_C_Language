#include<mystack.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initStack(Stack *stack,int elementSize,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(elementSize<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
if(successful) *successful=SUCCESSFUL;
}

void push(Stack *stack,void *ptr,int *successful,int *error){
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL){
if(error) *error=NULL_VALUE;
return;
}
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
if(ptr!=NULL){
node->ptr=(void *)malloc(stack->elementSize);
if(node->ptr==NULL){
free(node);
if(error) *error=MEM_ALLOC_ERR;
return;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
if(successful) *successful=SUCCESSFUL;
}
void pop(Stack *stack,void *ptr,int *successful,int *error){
if(successful) *successful=SUCCESSFUL;
if(error) *error=NO_ERROR;
if(stack==NULL || ptr==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(stack->top==NULL){
if(error) *error=EMPTY_STACK;
return;
}
StackNode *node;
node=stack->top;
stack->top=stack->top->next;
if(node->ptr==NULL){
ptr=node->ptr;
}
else{
memcpy(ptr,(const void *)node->ptr,stack->elementSize);
}
if(node->ptr!=NULL) free(node->ptr);
free(node);
stack->size--;
if(successful) *successful=SUCCESSFUL;
}
int isEmpty(Stack *stack,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL){
if(error) *error=NULL_VALUE;
return 1;
}
if(successful) *successful=SUCCESSFUL;
if(stack->top==NULL) return 1;
return 0;
}
void clearStack(Stack *stack,int *successful,int *error){
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL){
if(error) *error=NULL_VALUE;
return;
}
while(stack->top==NULL){
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
}
if(successful) *successful=SUCCESSFUL;
}