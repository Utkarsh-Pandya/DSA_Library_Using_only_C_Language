#ifndef __mylinkedlist__
#define __mylinkedlist__ 69
#include<myconst.h>
#include<myerr.h>
typedef struct __node{
void *ptr;
struct __node *next;
}Node;
typedef struct __linked_list{
Node *head;
int size;
int elementSize;
}LinkedList;
void initLinkedList(LinkedList *list,int es,int *successful,int *error);
void addToList(LinkedList *list,void *num,int *successful,int *error);
void insertIntoList(LinkedList *list,void *num,int index,int *successful,int *error);
void deleteFromList(LinkedList *list,int index,int *successful,int *error);
int sizeofList(LinkedList *list,int *successful,int *error);
int isListEmpty(LinkedList *list,int *successful,int *error);
void insertIntoListSorted(LinkedList *list,void *num,int (*p2f)(void *,void *),int *successful,int *error);
void getItemFromList(LinkedList *list,void *num,int index,int *successful,int *error);
void clearList(LinkedList *list,int *successful,int *error);
#endif