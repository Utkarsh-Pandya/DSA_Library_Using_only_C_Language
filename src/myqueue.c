#include<myqueue.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void initQueue(Queue *queue,int es,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(queue==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
queue->start=NULL;
queue->end=NULL;
queue->size=0;
queue->elementSize=es;
if(successful) *successful=SUCCESSFUL;
}

int isQueueEmpty(Queue *queue,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(queue==NULL){
if(error) *error=NULL_VALUE;
return 1;
}
if(successful) *successful=SUCCESSFUL;
return queue->size==0;
}

void addToQueue(Queue *queue,void *ptr,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
QueueNode *t;
if(queue==NULL){
if(error) *error=NULL_VALUE;
return;
}
t=(QueueNode *)malloc(sizeof(QueueNode));
if(t==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
if(ptr!=NULL){
t->ptr=(void *)malloc(queue->elementSize);
if(t->ptr==NULL){
free(t);
if(error) *error=MEM_ALLOC_ERR;
return;
}
memcpy(t->ptr,(const void *)ptr,queue->elementSize);
}
else{
t->ptr=ptr;
}
t->next=NULL;
if(queue->start==NULL){
queue->start=t;
queue->end=t;
}
else{
queue->end->next=t;
queue->end=t;
}
queue->size++;
if(successful) *successful=SUCCESSFUL;
}

void removeFromQueue(Queue *queue,void *ptr,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
int isSuccessful,errorNumber;
QueueNode *t;
if(queue==NULL || ptr==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(isQueueEmpty(queue,&isSuccessful,&errorNumber)){
if(error) *error=EMPTY_QUEUE;
return;
}
if(queue->start->ptr!=NULL){
memcpy(ptr,(const void *)queue->start->ptr,queue->elementSize);
}
else{
ptr=queue->start->ptr;
}
t=queue->start;
queue->start=queue->start->next;
if(t->ptr!=NULL) free(t->ptr);
free(t);
queue->size--;
if(queue->size==0) queue->end=NULL;
if(successful) *successful=SUCCESSFUL;
}

void clearQueue(Queue *queue,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
QueueNode *t;
if(queue==NULL){
if(error) *error=NULL_VALUE;
return;
}
while(queue->start!=NULL){
t=queue->start;
queue->start=queue->start->next;
if(t->ptr!=NULL) free(t->ptr);
free(t);
}
queue->start=NULL;
queue->end=NULL;
queue->size=0;
if(successful) *successful=SUCCESSFUL;
}