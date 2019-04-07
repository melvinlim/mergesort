#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ITERS 300000
#define NELEMENTS 20

#define printf

typedef int item;
item buffer[NELEMENTS];
void swap(item *ls,int x,int y){
	item tmp=ls[x];
	ls[x]=ls[y];
	ls[y]=tmp;
}
void merge(item *ls,int a,int b,int c){
	int xl=c-a;
	int n=b;
	int m=c;
	for(int i=0;i<xl;i++){
		buffer[i]=-1;
	}
	int a0=a;
	int xi=0;
	while((a<n)&&(b<m)){
		if(ls[a]<=ls[b]){
			buffer[xi++]=ls[a++];
		}else{
			buffer[xi++]=ls[b++];
		}
	}
	while(a<n){
		buffer[xi++]=ls[a++];
	}
	while(b<m){
		buffer[xi++]=ls[b++];
	}
	a=a0;
	for(xi=0;xi<xl;xi++){
		ls[a++]=buffer[xi];
	}
}
void mymergesort(item *ls,int a,int n){
	if(n<=1){
		return;
	}else if(n==2){
		if(ls[a]>ls[a+1])
			swap(ls,a,a+1);
		return;
	}
	int mid=n/2;
	mymergesort(ls,a,mid);
	mymergesort(ls,a+mid,n-mid);
	merge(ls,a,a+mid,a+n);
}
void generate(item *ls,int n,int x){
	srand(time(0)+x);
	for(int i=0;i<n;i++){
		ls[i]=rand()%NELEMENTS;
	}
}
void print(item *ls,int n){
	for(int i=0;i<n;i++){
		printf("%d ",ls[i]);
	}
	printf("\n");
}
void sortOnce(int nElements,int x){
	printf("generating...\n");
	item *ls=malloc(nElements*sizeof(item));
	generate(ls,nElements,x);
	print(ls,nElements);
	printf("sorting...\n");
	mymergesort(ls,0,nElements);
	print(ls,nElements);
	free(ls);
}
int main(){
	int i;
	for(i=1;i<=ITERS;i++){
		printf("Iteration: %d\n",i);
		sortOnce(NELEMENTS,i);
		printf("\n");
	}
	return 0;
}
