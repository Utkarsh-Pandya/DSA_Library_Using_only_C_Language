#ifndef __myarray__
#define __myarray__ 69
#include<myconst.h>
#include<myerr.h>

typedef struct __darray{
void **ptr;
int es;  //es stands for Element Size
int size;
int capacity;
}DArray;

void initDArray(DArray *arr,int elementSize,int *successful,int *error);
void addToArray(DArray *arr,void *num,int *successful,int *error);
int getSize(DArray *arr,int *successful,int *error);
int getCapacity(DArray *arr,int *successful,int *error);
void getFromArray(DArray *arr,int index,void *num,int *successful,int *error);
void getLastItem(DArray *arr,void *num,int *successful,int *error);
void updateInArray(DArray *arr,int index,void *num,int *successful,int *error);
void deleteLastItem(DArray *arr,int *successful,int *error);
void deleteArray(DArray *arr,int *successful,int *error);

#endif