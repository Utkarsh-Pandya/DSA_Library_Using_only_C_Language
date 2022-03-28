#include<myutils.h>
#include<stdlib.h>
#include<string.h>




void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error){
int size1,size2,size3;
void *tmp;
int i1,i2,i3;
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
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
tmp=(void *)malloc(es*size3);
if(tmp==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2){
if(p2f(x+(i1*es),x+(i2*es))<0){
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else{
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1){
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2){
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1){
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2){
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i2++;
i3++;
}
free(tmp);
if(successful) *successful=SUCCESSFUL;
}




void generateMaxHeap(void *x,int (*p2f)(void *,void *),int es,int lb,int ub,int *successful,int *error){
int y,size,ci,ri;
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
*error=MEM_ALLOC_ERR;
return;
}

size=ub-lb+1;
y=lb+1;
while(y<size){
ci=y;
while(ci>lb){
ri=lb+((ci-1)/2);
if(p2f(x+(ci*es),x+(ri*es))>0){
memcpy(g,(const void *)(x+(ci*es)),es);
memcpy(x+(ci*es),(const void *)(x+(ri*es)),es);
memcpy(x+(ri*es),(const void *)g,es);
ci=ri;
}
else{
break;
}
}
y++;
}
free(g);
if(successful) *successful=SUCCESSFUL;
}



void reverse(void *x,int es,int lb,int ub,int *successful,int *error){
int i,size;
void *g;
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(x==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
if(lb>ub){
if(error) *error=FALSE_INPUT;
return;
}
g=(void *)malloc(es);
if(g==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
size=ub-lb+1;
i=0;
while(i<size/2){
memcpy(g,(const void *)(x+((lb+i)*es)),es);
memcpy(x+((lb+i)*es),(const void *)(x+((ub-i)*es)),es);
memcpy(x+((ub-i)*es),(const void *)g,es);
i++;
}
if(successful) *successful=SUCCESSFUL;
}



int numberOfDigits(int num,int *successful,int *error){
int dc;
dc=1;
while(num>9){
num=num/10;
dc++;
}
if(successful) *successful=SUCCESSFUL;
if(error) *error=NO_ERROR;
return dc;
}



int nthDigit(int num,int n,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(num<0 || n<=0){
if(error) *error=FALSE_INPUT;
return -1;
}
int i,j,k;
i=1;
while(--n) i*=10;
j=i*10;
k=num%j;
k=k/i;
if(successful) *successful=SUCCESSFUL;
return k;
}




int intComparator(void *left,void *right){
return (*((int *)left))-(*((int *)right));
}




void swap(void *a,void *b,int es,int *successful,int *error){
if(successful) *successful=FAILED;
if(error) *error=NO_ERROR;
if(a==NULL || b==NULL){
if(error) *error=NULL_VALUE;
return;
}
if(es<=0){
if(error) *error=ELEM_SIZE_NEG;
return;
}
void *c;
c=(void *)malloc(es);
if(c==NULL){
if(error) *error=MEM_ALLOC_ERR;
return;
}
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
if(successful) *successful=SUCCESSFUL;
}



int maxSubArraySum(int *arr,int lb,int ub,int *successful,int *error){
if(*successful) *successful=FAILED;
if(*error) *error=NO_ERROR;
if(arr==NULL){
if(*error) *error=NULL_VALUE;
return -1;
}
if(lb>ub){
if(*error) *error=FALSE_INPUT;
return 0;
}
int i,max,curMax;
max=INT_MIN;
curMax=0;
for(i=lb;i<=ub;i++){
curMax+=arr[i];
if(curMax > max) max=curMax;
if(curMax < 0) curMax=0;
}
if(*successful) *successful=FAILED;
return max;
}



