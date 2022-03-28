#ifndef __myqueue__
#define __myqueue__ 69
#include<myconst.h>
#include<myerr.h>
typedef struct _queue_node{
void *ptr;
struct _queue_node *next;
}QueueNode;
typedef struct _queue{
QueueNode *start;
QueueNode *end;
int elementSize;
int size;
}Queue;
void initQueue(Queue *queue,int elementSize,int *successful,int *error);
void addToQueue(Queue *queue,void *ptr,int *successful,int *error);
void removeFromQueue(Queue *queue,void *ptr,int *successful,int *error);
int isQueueEmpty(Queue *queue,int *successful,int *error);
void clearQueue(Queue *queue,int *successful,int *error);
#endif