#ifndef __mysort__
#define __mysort__ 69
#include<myconst.h>
#include<myerr.h>
#include<myqueue.h>
#include<mystack.h>
#include<myutils.h>
#include<mylinkedlist.h>
void bubbleSort(void *x,int (*p2f)(void *,void *),int elementSize,int lb,int ub,int *successful,int *error);
void linearSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void selectionSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void insertionSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void quickSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void mergeSort(void *x,int (*p2f)(void *,void *),int es,int lowerBound,int upperBound,int *successful,int *error);
void heapSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void radixSort2(int *x,int lb,int ub,int *successful,int *error);
void radixSort(int *x,int lb,int ub,int *successful,int *error);
void countingSort(int *x,int lb,int ub,int *successful,int *error);
void externalSort(char *fileName,int es,int (*p2f)(void *,void *),int *successful,int *error);
void pancakeSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void addressCalculationSort(int *x,int lb,int ub,int *successful,int *error);
void gnomeSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void oddEvenSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void timSort(char *name,int es,int (*p2f)(void *,void *),int *successful,int *error);
void pigeonholeSort(int *x,int lb,int ub,int *successful,int *error);
void stoogeSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void cocktailShakerSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void binaryInsertionSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
#endif