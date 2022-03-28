#include<mylinkedlist.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void initLinkedList(LinkedList *list,int es,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
list->size=0;
list->head=NULL;
list->elementSize=es;
if(successful) *successful=SUCCESSFUL;
}

void addToList(LinkedList *list,void *num,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL || num==NULL){
if(error) *error=NULL_VALUE;
return;
}
Node *t;
t=(Node *)malloc(sizeof(Node));
if(t==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
//t->ptr=num;
t->ptr=(void *)malloc(list->elementSize);
if(t->ptr==NULL){
if(error) *error=MEM_ALLOC_ERR;
free(t);
return;
}
memcpy(t->ptr,(const void *)num,list->elementSize);
t->next=NULL;
if(list->head==NULL){
list->head=t;
}
else{
Node *temp;
temp=list->head;
while(temp->next!=NULL) temp=temp->next;
temp->next=t;
}
list->size++;
if(successful) *successful=SUCCESSFUL;
}

void insertIntoList(LinkedList *list,void *num,int index,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL || num==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(index<0){
if(error) *error=FALSE_INPUT;
return;
}
if(index>=list->size){
int isSuccessful,errorNumber;
addToList(list,num,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
if(successful) *successful=SUCCESSFUL;
return;
}
Node *t;
t=(Node *)malloc(sizeof(Node));
if(t==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
//t->ptr=num;
t->ptr=(void *)malloc(list->elementSize);
if(t->ptr==NULL){
if(error) *error=MEM_ALLOC_ERR;
free(t);
return;
}
memcpy(t->ptr,(const void *)num,list->elementSize);
t->next=NULL;
if(index==0){
t->next=list->head;
list->head=t;
list->size++;
if(successful) *successful=SUCCESSFUL;
return;
}
Node *temp;
temp=list->head;
while(--index) temp=temp->next;
t->next=temp->next;
temp->next=t;
list->size++;
if(successful) *successful=SUCCESSFUL;
}

void deleteFromList(LinkedList *list,int index,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(index<0 || index>=list->size){
if(error) *error=FALSE_INPUT;
return;
}
Node *temp;
temp=list->head;
while(--index) temp=temp->next;
Node *t;
t=temp->next;
temp->next=t->next;
free(t->ptr);
free(t);
if(successful) *successful=SUCCESSFUL;
}

int sizeofList(LinkedList *list,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL){
if(error) *error=NULL_VALUE;
return 0;
}
if(successful) *successful=SUCCESSFUL;
return list->size;
}

int isListEmpty(LinkedList *list,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL){
if(error) *error=NULL_VALUE;
return 1;
}
if(successful) *successful=SUCCESSFUL;
return list->size==0;
}

void insertIntoListSorted(LinkedList *list,void *num,int (*p2f)(void *,void *),int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL || num==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
int isSuccessful,errorNumber;
if(list->head==NULL){
addToList(list,num,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
}
else{
if(successful) *successful=SUCCESSFUL;
}
return;
}
int index;
index=0;
Node *temp;
temp=list->head;
//while(temp->ptr<num){
while(p2f(temp->ptr,num)<0){
index++;
if(temp->next==NULL) break;
temp=temp->next;
}
if(index>=list->size){
addToList(list,num,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
if(successful) *successful=SUCCESSFUL;
return;
}
insertIntoList(list,num,index,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
if(successful) *successful=SUCCESSFUL;
}

void getItemFromList(LinkedList *list,void *num,int index,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL || num==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(index<0 || index>=list->size){
if(error) *error=FALSE_INPUT;
return;
}
Node *temp;
temp=list->head;
while(index--) temp=temp->next;
//return temp->ptr;
memcpy(num,(const void *)temp->ptr,list->elementSize);
if(successful) *successful=SUCCESSFUL;
}

void clearList(LinkedList *list,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(list==NULL){
if(error) *error=NULL_VALUE;
return;
}
Node *temp;
temp=list->head;
while(temp){
Node *t;
t=temp;
temp=temp->next;
free(t->ptr);
free(t);
}
list->head=NULL;
list->size=0;
if(successful) *successful=SUCCESSFUL;
}