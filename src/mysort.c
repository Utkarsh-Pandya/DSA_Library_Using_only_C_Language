#include<mysort.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void bubbleSort(void *x,int (*p2f)(void *,void *),int elementSize,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(elementSize<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
int e,f,m,size;
void *g;
g=(void *)malloc(elementSize);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
size=ub-lb+1;
m=size-2;
while(m>=lb){
e=lb;
f=lb+1;
while(e<=m){
if(p2f(x+(f*elementSize),x+(e*elementSize))<0){
memcpy(g,(const void *)(x+(e*elementSize)),elementSize);
memcpy(x+(e*elementSize),(const void *)(x+(f*elementSize)),elementSize);
memcpy(x+(f*elementSize),(const void *)g,elementSize);
}
e++;
f++;
}
m--;
}
free(g);
if(successful) *successful=SUCCESSFUL;
}



void linearSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
int i,j,size;
void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
size=ub-lb+1;
for(i=lb;i<size-1;i++){
for(j=i+1;j<size;j++){
if(p2f(x+(j*es),x+(i*es))<0){
memcpy(g,(const void *)(x+(i*es)),es);
memcpy(x+(i*es),(const void *)(x+j*es),es);
memcpy(x+(j*es),(const void *)g,es);
}
}
}
free(g);
if(successful) *successful=SUCCESSFUL;
}



void selectionSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
int i,j,min,size;
size=ub-lb+1;
for(i=lb;i<size-1;i++){
min=i;
for(j=i+1;j<size;j++){
if(p2f(x+(j*es),x+(min*es))<0) min=j;
}
memcpy(g,(const void *)(x+(min*es)),es);
memcpy(x+(min*es),(const void *)(x+(i*es)),es);
memcpy(x+(i*es),(const void *)g,es);
}
free(g);
if(successful) *successful=SUCCESSFUL;
}



void insertionSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
int e,f,size;
e=lb+1;
size=ub-lb+1;
while(e<size){
f=e-1;
memcpy(g,(const void *)(x+(e*es)),es);
while(f>=lb && p2f(x+(f*es),g)>0){
memcpy(x+((f+1)*es),(const void *)(x+(f*es)),es);
f--;
}
memcpy(x+((f+1)*es),(const void *)g,es);
e++;
}
free(g);
if(successful) *successful=SUCCESSFUL;
}



void quickSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}

int isSuccessful,errorNumber;
struct LBUB{
int lb,ub;
};
struct LBUB lbub;
lbub.lb=lb;
lbub.ub=ub;
int a,b,pp,e,f;
Stack stack;
initStack(&stack,sizeof(struct LBUB),&isSuccessful,&errorNumber);
push(&stack,&lbub,&isSuccessful,&errorNumber);
if(isSuccessful==0){
if(error) *error=errorNumber;
return;
}
while(!isEmpty(&stack,&isSuccessful,&errorNumber)){
pop(&stack,&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
e=a;
f=b;
while(e<f){
while(e<b && p2f(x+(e*es),x+(a*es))<=0) e++;
while(p2f(x+(f*es),x+(a*es))>0) f--;
if(e<f){
memcpy(g,(const void *)(x+(e*es)),es);
memcpy(x+(e*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
else{
memcpy(g,(const void *)(x+(a*es)),es);
memcpy(x+(a*es),(const void *)(x+(f*es)),es);
memcpy(x+(f*es),(const void *)g,es);
}
}
pp=f;
if(pp+1<b){
lbub.lb=pp+1;
lbub.ub=b;
push(&stack,&lbub,&isSuccessful,&errorNumber);
if(isSuccessful==0){
if(error) *error=errorNumber;
return;
}
}
if(a<pp-1){
lbub.lb=a;
lbub.ub=pp-1;
push(&stack,&lbub,&isSuccessful,&errorNumber);
if(isSuccessful==0){
if(error) *error=errorNumber;
return;
}
}
}
free(g);
if(successful) *successful=SUCCESSFUL;
}



void mergeSort(void *x,int (*p2f)(void *,void *),int es,int lowerBound,int upperBound,int *successful,int *error){
struct LBUB{
int lb,ub;
};
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
int isSuccessful,errorNumber;
struct LBUB lbub;
int a,b,mid;
lbub.lb=lowerBound;
lbub.ub=upperBound;
Stack stack1;
Stack stack2;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful){
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
while(!isEmpty(&stack1,&isSuccessful,&errorNumber)){
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful){
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid){
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful){
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(mid+1<b){
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful){
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber)){
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,p2f,es,a,mid,mid+1,b,&isSuccessful,&errorNumber);
if(!isSuccessful){
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(successful) *successful=SUCCESSFUL;
}




void heapSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
int y,ri,lci,rci,swi,ci,size;
void *g;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
*error=NULL_VALUE;
return;
}
if(es<=0){
*error=ELEM_SIZE_NEG;
return;
}
g=(void *)malloc(es);
if(g==NULL){
*error=MEM_ALLOC_ERR;
return;
}

int isSuccessful,errorNumber;
generateMaxHeap((void *)x,p2f,es,lb,ub,&isSuccessful,&errorNumber);
if(!isSuccessful){
if(error) *error=errorNumber;
return;
}
y=ub;
while(y>lb){
memcpy(g,(const void *)(x+(lb*es)),es);
memcpy(x+(lb*es),(const void *)(x+(y*es)),es);
memcpy(x+(y*es),(const void *)g,es);
y--;
ri=0;
while(ri<y-lb){
lci=lb+((ri*2)+1);
if(lci>y) break;
rci=lci+1;
if(rci>y){
swi=lci;
}
else{
if(p2f(x+(lci*es),x+(rci*es))>0){
swi=lci;
}
else{
swi=rci;
}
}
ri+=lb;
if(p2f(x+(swi*es),x+(ri*es))>0){
memcpy(g,(const void *)(x+(swi*es)),es);
memcpy(x+(swi*es),(const void *)(x+(ri*es)),es);
memcpy(x+(ri*es),(const void *)g,es);
ri=swi-lb;
}
else{
break;
}
}
}
free(g);
if(successful) *successful=SUCCESSFUL;
}




void radixSort2(int *x,int lb,int ub,int *successful,int *error){
int isSuccessful,errorNumber;
int y,i,e,f,largest,num,dc,k;
Queue queue[10];
for(i=0;i<=9;i++){
initQueue(&queue[i],sizeof(int),&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
}

//finding largest number
largest=x[lb];
for(i=lb;i<=ub;i++){
if(x[i]>largest) largest=x[i];
}
//number of digits in the largest number
dc=numberOfDigits(largest,&isSuccessful,&errorNumber);

k=1;
e=10;
f=1;
while(k<=dc){
//spread in queues
y=lb;
while(y<=ub){
num=x[y];
i=(num%e)/f;
addToQueue(&queue[i],&num,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
y++;
}

//collecting back in the array
y=lb;
for(i=0;i<=9;i++){
while(!isQueueEmpty(&queue[i],&isSuccessful,&errorNumber)){
removeFromQueue(&queue[i],&num,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
x[y]=num;
y++;
}
}
e=e*10;
f=f*10;
k++;
}
}
void radixSort(int *x,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL){
if(error) *error=NULL_VALUE;
return;
}
int isSuccessful,errorNumber;
int lb1,lb2,ub1,ub2,neg,i,g;
neg=0;
for(i=lb;i<=ub;i++){
if(x[i]<0){
g=x[i];
x[i]=x[neg];
x[neg]=g;
neg++;
}
}
lb1=lb;
ub1=neg-1;
lb2=neg;
ub2=ub;
for(i=lb1;i<=ub1;i++) x[i]=x[i]*(-1);
radixSort2(x,lb1,ub1,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
radixSort2(x,lb2,ub2,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
reverse((void *)x,sizeof(int),lb1,ub1,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
for(i=lb1;i<=ub1;i++) x[i]=(-1)*x[i];

if(successful) *successful=SUCCESSFUL;
}



void countingSort(int *x,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL){
if(error) *error=NULL_VALUE;
return;
}
int i,largest,z;
int *tmp;
largest=x[lb];
for(i=lb+1;i<=ub;i++){
if(x[i]>largest) largest=x[i];
}
tmp=(int *)malloc((largest+1)*sizeof(int));
if(tmp==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
for(i=0;i<=largest;i++) tmp[i]=0;
for(i=lb;i<=ub;i++) tmp[x[i]]++;
z=0;
for(i=0;i<=largest;i++){
while(tmp[i]--){
x[z]=i;
z++;
}
}
if(successful) *successful=SUCCESSFUL;
}



void externalSort(char *fileName,int es,int (*p2f)(void *,void *),int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(fileName==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
FILE *fp;
int num,i,j,e,t,isSuccessful,errorNumber;
long int x;
char *name;
name=(char *)malloc(sizeof(char)*7);
if(name==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
name[0]='d';
name[1]='a';
name[2]='t';
name[3]='a';
name[5]='.';
name[6]='d';

fp=fopen(fileName,"rb");
if(fp==NULL){
if(error) *error=FILE_NOT_FOUND;
free(name);
return;
}
fseek(fp,0,SEEK_END);
x=ftell(fp);
rewind(fp);

FILE *data[10];
j=x/10;
for(i=0;i<=9;i++){
name[4]=i+48;
data[i]=fopen(name,"wb");
if(data[i]==NULL){
if(error) *error=NOT_ENOUGH_MEM;
for(j=0;j<i;j++) fclose(data[j]);
fclose(fp);
free(name);
return;
}
while(ftell(fp) < (i+1)*j){
fread(&num,es,1,fp);
fwrite(&num,es,1,data[i]);
}
}
while(ftell(fp) < x){
fread(&num,es,1,fp);
fwrite(&num,es,1,data[9]);
}
for(i=0;i<=9;i++) fclose(data[i]);
fclose(fp);

for(i=0;i<=9;i++){
name[4]=i+48;
data[i]=fopen(name,"rb");
if(data[i]==NULL){
if(error) *error=FILE_NOT_FOUND;
free(name);
return;
}
void *temp;
fseek(data[i],0,SEEK_END);
t=ftell(data[i]);
t/=es;
rewind(data[i]);
temp=(void *)malloc(es*t);
if(temp==NULL){
if(error) *error=MEM_ALLOC_ERR;
fclose(data[i]);
free(name);
return;
}
j=0;
while(fread(&num,es,1,data[i])==1){
memcpy(temp+(j*es),(const void *)&num,es);
j++;
}
fclose(data[i]);
quickSort((void *)temp,p2f,es,0,t-1,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
free(name);
return;
}
data[i]=fopen(name,"wb");
if(data[i]==NULL){
if(error) *error=NOT_ENOUGH_MEM;
free(name);
return;
}
for(j=0;j<t;j++){
memcpy(&num,(const void *)(temp+(es*j)),es);
fwrite(&num,es,1,data[i]);
}
free(temp);
fclose(data[i]);
}

//MERGEING
fp=fopen(fileName,"wb");
for(i=0;i<=9;i++){
name[4]=i+48;
data[i]=fopen(name,"rb");
}
int index[10];
void *temp;
temp=(void *)malloc(es*10);
if(temp==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
for(i=0;i<=9;i++){
index[i]=i;
fread(&num,es,1,data[i]);
memcpy(temp+(es*i),(const void *)&num,es);
}
while(1){
e=0;
while((index[e]==(-1)) && e<=9) e++;
if(e>9) break;
i=e+1;
while(i<=9){
if(index[i]==(-1)){
i++;
continue;
}
if(p2f(temp+(es*i),temp+(es*e))<0) e=i;
i++;
}
memcpy(&num,(const void *)(temp+(es*e)),es);
fwrite(&num,es,1,fp);
if(fread(&num,es,1,data[e])==1){
memcpy(temp+(es*e),(const void *)&num,es);
}
else{
index[e]=(-1);
}
}
free(temp);
free(name);
for(i=0;i<=9;i++) fclose(data[i]);
for(i=0;i<=9;i++){
name[4]=i+48;
data[i]=fopen(name,"w");
fclose(data[i]);
}
fclose(fp);
if(successful) *successful=SUCCESSFUL;
}




void pancakeSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}

int z,i,j,isSuccessful,errorNumber;
i=ub;
while(lb<i){
z=lb;
for(j=lb+1;j<=i;j++){
//if(x[j]>x[z]) z=j;
if(p2f(x+(j*es),x+(z*es))>0) z=j;
}
reverse(x,es,lb,z,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
reverse(x,es,lb,i,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
i--;
}
if(successful) *successful=SUCCESSFUL;
}



void addressCalculationSort(int *x,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(lb<0 || ub<0 || ub<lb){
if(error) *error=FALSE_INPUT;
return;
}
int largest,nod,num,i,j,z,size,n,isSuccessful,errorNumber;
LinkedList ll[10];
for(i=0;i<=9;i++) initLinkedList(&ll[i],sizeof(int),&isSuccessful,&errorNumber);
size=ub-lb+1;
largest=x[lb];
if(x[lb]<0){
if(error) *error=INVALID_VALUE_IN_ARR;
return;
}
for(i=1;i<size;i++){
if(x[lb+i]<0){
if(error) *error=INVALID_VALUE_IN_ARR;
return;
}
if(x[lb+i]>largest) largest=x[lb+i];
}
nod=numberOfDigits(largest,&isSuccessful,&errorNumber);
for(i=0;i<size;i++){
n=nthDigit(x[lb+i],nod,&isSuccessful,&errorNumber);
insertIntoListSorted(&ll[n],&x[lb+i],intComparator,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
}
z=0;
for(i=0;i<=9;i++){
n=sizeofList(&ll[i],&isSuccessful,&errorNumber);
for(j=0;j<n;j++){
getItemFromList(&ll[i],(void *)&num,j,&isSuccessful,&errorNumber);
x[z]=num;
z++;
}
}
for(i=0;i<=9;i++) clearList(&ll[i],&isSuccessful,&errorNumber);
if(successful) *successful=SUCCESSFUL;
}




void gnomeSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(lb<0 || ub<0 || ub<lb){
if(error) *error=FALSE_INPUT;
return;
}

void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}

int j;
j=lb;
while(j<=ub){
if(j==lb){
j++;
continue;
}
if(p2f(x+(es*j),x+(es*(j-1)))<0){
memcpy(g,(const void *)(x+(es*j)),es);
memcpy(x+(es*j),(const void *)(x+(es*(j-1))),es);
memcpy(x+(es*(j-1)),(const void *)g,es);
j--;
}
else{
j++;
}
}
if(successful) *successful=SUCCESSFUL;
}




// Odd-Even Sort is also known as Brick Sort
void oddEvenSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(lb<0 || ub<0 || ub<lb){
if(error) *error=FALSE_INPUT;
return;
}

void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}

int i,count;
do{
count=0;
for(i=lb+1;i<ub;i+=2){
if(p2f(x+(es*i),x+(es*(i+1)))>0){
memcpy(g,(const void *)(x+(es*i)),es);
memcpy(x+(es*i),(const void *)(x+(es*(i+1))),es);
memcpy(x+(es*(i+1)),(const void *)g,es);
count++;
}
}
for(i=lb;i<ub;i+=2){
if(p2f(x+(es*i),x+(es*(i+1)))>0){
memcpy(g,(const void *)(x+(es*i)),es);
memcpy(x+(es*i),(const void *)(x+(es*(i+1))),es);
memcpy(x+(es*(i+1)),(const void *)g,es);
count++;
}
}
}while(count!=0);
if(successful) *successful=SUCCESSFUL;
}




void timSort(char *name,int es,int (*p2f)(void *,void *),int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(name==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
int n,i,t,j,z,e,num,isSuccessful,errorNumber;
FILE *fp;
char ch[4];
ch[0]=97;
ch[1]=97;
ch[2]='.';
ch[3]='d';
fp=fopen(name,"rb");
if(fp==NULL){
if(error) *error=FILE_NOT_FOUND;
free(name);
return;
}
fseek(fp,0,SEEK_END);
t=ftell(fp);
t=t/es;
if(t%64==0) n=t/64;
else n=(t/64)+1;
rewind(fp);
FILE *fp1[n];
int arr[64];
i=0;
while(fread(&num,es,1,fp)==1){
arr[i]=num;
i++;
if(i%64==0){
i=0;
insertionSort(arr,intComparator,es,0,63,&isSuccessful,&errorNumber);
if(isSuccessful==FAILED){
if(error) *error=errorNumber;
return;
}
if(ch[0]>122){
ch[0]=97;
ch[1]++;
}
fp1[0]=fopen(ch,"wb");
if(fp1[0]==NULL){
if(error) *error=NOT_ENOUGH_MEM;
fclose(fp);
return;
}

for(j=0;j<64;j++){
num=arr[j];
fwrite(&num,es,1,fp1[0]);
}
fclose(fp1[0]);
ch[0]++;
}
}
if(t%64!=0){
insertionSort(arr,intComparator,es,0,i-1,&isSuccessful,&errorNumber);
if(ch[0]>122){
ch[0]=97;
ch[1]++;
}
fp1[0]=fopen(ch,"wb");
for(j=0;j<i;j++){
num=arr[j];
fwrite(&num,es,1,fp1[0]);
}
fclose(fp1[0]);
}

//MERGEING
fp=fopen(name,"wb");
ch[0]=97;
ch[1]=97;
for(i=0;i<n;i++){
if(ch[0]>122){
ch[0]=97;
ch[1]++;
}
fp1[i]=fopen(ch,"rb");
ch[0]++;
}
int temp[n][2];
for(i=0;i<n;i++){
temp[i][1]=i;
fread(&num,es,1,fp1[i]);
temp[i][0]=num;
}
while(1){
e=0;
while((temp[e][1]==(-1)) && e<n) e++;
if(e>=n) break;
i=e+1;
while(i<n){
if(temp[i][1]==(-1)){
i++;
continue;
}
if(temp[i][0] < temp[e][0]) e=i;
i++;
}
num=temp[e][0];
fwrite(&num,es,1,fp);
if(fread(&num,es,1,fp1[e])==1){
temp[e][0]=num;
}
else{
temp[e][1]=(-1);
}
}
for(i=0;i<n;i++) fclose(fp1[i]);
fclose(fp);
ch[0]=97;
ch[1]=97;
for(i=0;i<n;i++){
if(ch[0]>122){
ch[0]=97;
ch[1]++;
}
fp1[i]=fopen(ch,"w");
fclose(fp1[i]);
ch[0]++;
}
if(successful) *successful=SUCCESSFUL;
}




void pigeonholeSort(int *x,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(lb>ub){
if(error) *error=FALSE_INPUT;
return;
}
int min,max,i,range,j,isSuccessful,errorNumber,num;
min=x[lb];
max=x[lb];
for(i=lb+1;i<=ub;i++){
if(x[i]<min) min=x[i];
if(x[i]>max) max=x[i];
}
range=max-min+1;
Stack stack[range];
for(i=0;i<range;i++) initStack(&stack[i],sizeof(int),&isSuccessful,&errorNumber);
for(i=lb;i<=ub;i++) push(&stack[x[i]-min],&x[i],&isSuccessful,&errorNumber);
j=0;
for(i=0;i<range;i++){
while(!isEmpty(&stack[i],&isSuccessful,&errorNumber)){
pop(&stack[i],&num,&isSuccessful,&errorNumber);
x[j]=num;
j++;
}
}
if(successful) *successful=SUCCESSFUL;
}




void stoogeSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(lb<0 || ub<0 || ub<lb){
if(error) *error=FALSE_INPUT;
return;
}
int isSuccessful,errorNumber;
if(p2f(x+lb*es,x+ub*es)>0) swap(x+lb*es,x+ub*es,es,&isSuccessful,&errorNumber);
if(ub-lb+1 > 3){
int temp;
temp=ub-lb+1;
temp -= temp/3;
temp-=1;
stoogeSort((void *)x,p2f,es,lb,lb+temp,&isSuccessful,&errorNumber);
stoogeSort((void *)x,p2f,es,ub-temp,ub,&isSuccessful,&errorNumber);
stoogeSort((void *)x,p2f,es,lb,lb+temp,&isSuccessful,&errorNumber);
}
else if((ub-lb+1) == 3){
if(p2f(x+lb*es,x+(lb+1)*es)>0) swap(x+lb*es,x+(lb+1)*es,es,&isSuccessful,&errorNumber);
if(p2f(x+(lb+1)*es,x+ub*es)>0) swap(x+ub*es,x+(lb+1)*es,es,&isSuccessful,&errorNumber);
if(p2f(x+lb*es,x+(lb+1)*es)>0) swap(x+lb*es,x+(lb+1)*es,es,&isSuccessful,&errorNumber);
}
if(successful) *successful=SUCCESSFUL;
}





void cocktailShakerSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(lb<0 || ub<0 || ub<lb){
if(error) *error=FALSE_INPUT;
return;
}

int isSuccessful,errorNumber;
int i,count;
while(ub>lb){
count=0;
for(i=lb;i<ub;i++){
if(p2f(x+i*es,x+(i+1)*es)>0){
swap(x+i*es,x+(i+1)*es,es,&isSuccessful,&errorNumber);
count++;
}
}
if(count==0) break;
count=0;
ub--;
for(i=ub;i>lb;i--){
if(p2f(x+i*es,x+(i-1)*es)<0){
swap(x+i*es,x+(i-1)*es,es,&isSuccessful,&errorNumber);
count++;
}
}
if(count==0) break;
lb++;
}
if(successful) *successful=SUCCESSFUL;
}




void binaryInsertionSort(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL || p2f==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(lb<0 || ub<0 || ub<lb){
if(error) *error=FALSE_INPUT;
return;
}

void *g;
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}

int i,si,ei,mid,j;
i=1;
while(i<=ub){
si=lb;
ei=i-1;
mid=si+(ei-si)/2;
while(si<=ei){
if(p2f(x+mid*es,x+i*es)==0) break;
if(p2f(x+mid*es,x+i*es)<0) si=mid+1;
else if(p2f(x+mid*es,x+i*es)>0) ei=mid-1;
mid=si+(ei-si)/2;
}
if(p2f(x+mid*es,x+i*es)==0) si=mid;
memcpy(g,(const void *)(x+i*es),es);
j=i;
while(j>si){
memcpy(x+j*es,(const void *)(x+(j-1)*es),es);
j--;
}
memcpy(x+si*es,(const void *)g,es);
i++;
}
if(successful) *successful=SUCCESSFUL;
}




