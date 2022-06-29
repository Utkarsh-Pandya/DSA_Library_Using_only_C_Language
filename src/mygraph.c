#include<mygraph.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


Graph* createGraph(int ver,int t,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(ver<0 || t<0 || t>1){
if(error) *error=FALSE_INPUT;
return NULL;
}
Graph *graph;
int i,e,s;
graph->type=t;
graph->vertex = ver;
graph->Edges=0;
graph->adjList = (LinkedList *)malloc(ver*(sizeof(LinkedList)));
if(graph->adjList == NULL){
if(error) *error=MEM_ALLOC_ERR;
return NULL;
}
for(i=0;i<ver;i++){
initLinkedList(&graph->adjList[i],2*sizeof(int),&s,&e);
if(s==FAILED){
if(error) *error=e;
return NULL;
}
}
if(successful) *successful=SUCCESSFUL;
return graph;
}

void addEdge(Graph* graph,int src,int dest,int weight,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(graph == NULL){
if(error) *error=NULL_VALUE;
return;
}
int e,s;
int a[2];
a[0]=dest;
a[1]=weight;
graph->Edges++;
addToList(&graph->adjList[src],a,&s,&e);
if(s==FAILED){
if(error) *error=e;
return;
}
if(graph->type == 1){
a[0]=src;
a[1]=weight;
addToList(&graph->adjList[dest],a,&s,&e);
if(s==FAILED){
if(error) *error=e;
return;
}
}
if(successful) *successful=SUCCESSFUL;
}

void printGraph(Graph* graph,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(graph == NULL){
if(error) *error=NULL_VALUE;
return;
}
int i,s,e,v;
v=graph->vertex;
printf("no of vertices: %d\n",v);
for(i=0;i<v;i++){
printf("%d -->",i);
int j,n=sizeofList(&graph->adjList[i],&s,&e);
if(s==FAILED){
if(error) *error=e;
return;
}
for(j=0;j<n;j++){
int num[2];
getItemFromList(&graph->adjList[i],&num,j,&s,&e);
if(s==FAILED){
if(error) *error=e;
return;
}
printf(" %d(%d)",num[0],num[1]);
}
printf("\n");
}
if(successful) *successful=SUCCESSFUL;
}

