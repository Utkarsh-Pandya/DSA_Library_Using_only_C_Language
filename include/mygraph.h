#ifndef __mygraph__
#define __mygraph__ 69
#include<myconst.h>
#include<myerr.h>
#include<mylinkedlist.h>
typedef struct __graph{
int vertex;
int type;
LinkedList *adjList;
int Edges;
}Graph;

Graph* createGraph(int ver,int t,int *successful,int *error);
void addEdge(Graph* graph,int src,int dest,int weight,int *successful,int *error);
void printGraph(Graph* graph,int *successful,int *error);
#endif
