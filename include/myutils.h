#ifndef __myutils__
#define __myutils__ 69
#include<myconst.h>
#include<myerr.h>
void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error);
void generateMaxHeap(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error);
void reverse(void *x,int es,int lb,int ub,int *successful,int *error);
int numberOfDigits(int num,int *successful,int *error);
int nthDigit(int num,int n,int *successful,int *error);
int intComparator(void *left,void *right);
void swap(void *a,void *b,int es,int *successful,int *error);
int maxSubArraySum(int *arr,int lb,int ub,int *successful,int *error);
#endif