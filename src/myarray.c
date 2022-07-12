#include<myarray.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void initDArray(DArray *arr,int elementSize,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(elementSize<0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
arr->size=0;
arr->capacity=0;
arr->es=elementSize;
arr->ptr=NULL;
//ptr=(int **)malloc(10*sizeof(int *));
if(successful) *successful=SUCCESSFUL;
}


void addToArray(DArray *arr,void *num,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(num==NULL || arr==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(arr->size == arr->capacity){
int i,x;
x=(arr->capacity)/10;
if((arr->capacity)%100 == 0){
void **temp;
temp=(void **)malloc((x+10)*sizeof(int *));
if(temp==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
for(i=0;i<x;i++){
//temp[i]=arr->ptr[i];
memcpy(temp+sizeof(int *)*i,(const void *)(arr->ptr+sizeof(int *)*i),sizeof(int *));
}
free(arr->ptr);
arr->ptr=temp;
}
void *temp;
temp=(void *)malloc(10*arr->es);
if(temp==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
arr->ptr[arr->size/10]=temp;
//memcpy(arr->ptr+sizeof(int *)*(arr->size/10),(const void *)temp,sizeof(int *));
arr->capacity=arr->capacity+10;
}
//arr->ptr[arr->size/10][arr->size%10]=num;
memcpy(arr->ptr[arr->size/10]+arr->es*(arr->size%10),(const void *)num,arr->es);
arr->size++;
if(successful) *successful=SUCCESSFUL;
}


int getSize(DArray *arr,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL){
if(error) *error=NULL_VALUE;
return -1;
}
if(successful) *successful=SUCCESSFUL;
return arr->size;
}


int getCapacity(DArray *arr,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL){
if(error) *error=NULL_VALUE;
return -1;
}
if(successful) *successful=SUCCESSFUL;
return arr->capacity;
}


void getFromArray(DArray *arr,int index,void *num,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL || num==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(index<0 || index>=arr->size){
if(error) *error=FALSE_INPUT;
return;
}
//return arr->ptr[index/10][index%10];
memcpy(num,(const void *)(arr->ptr[index/10]+arr->es*(index%10)),arr->es);
if(successful) *successful=SUCCESSFUL;
}


void getLastItem(DArray *arr,void *num,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL || num==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(arr->size>0){
int e,s;
getFromArray(arr,arr->size-1,num,&s,&e);
if(s==FAILED){
if(error) *error=e;
return;
}
}
if(successful) *successful=SUCCESSFUL;
}


void updateInArray(DArray *arr,int index,void *num,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL || num==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(index<0 && index>=arr->size){
if(error) *error=FALSE_INPUT;
return;
}
//arr->ptr[index/10][index%10]=num;
memcpy(arr->ptr[index/10]+arr->es*(index%10),(const void *)num,arr->es);
if(successful) *successful=SUCCESSFUL;
}


void deleteLastItem(DArray *arr,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(arr->size>0){
arr->size--;
}
if(successful) *successful=SUCCESSFUL;
}


void deleteArray(DArray *arr,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(arr==NULL){
if(error) *error=NULL_VALUE;
return;
}
int i,n;
n=arr->capacity/10;
for(i=0;i<n;i++){
free(arr->ptr[i]);
}
free(arr->ptr);
arr->size=0;
arr->capacity=0;
if(successful) *successful=SUCCESSFUL;
}


