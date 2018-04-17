#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int item;
void swap(item *ls,int x,int y){
	item tmp=ls[x];
	ls[x]=ls[y];
	ls[y]=tmp;
}
void merge(item *ls,int a,int b,int c){
	int xl=c-a;
	int n=b;
	int m=c;
	item *x=malloc(xl*sizeof(item));
	for(int i=0;i<xl;i++){
		x[i]=-1;
	}
	int a0=a;
	int xi=0;
	while((a<n)&&(b<m)){
		if(ls[a]<=ls[b]){
			x[xi++]=ls[a++];
		}else{
			x[xi++]=ls[b++];
		}
	}
	while(a<n){
		x[xi++]=ls[a++];
	}
	while(b<m){
		x[xi++]=ls[b++];
	}
	a=a0;
	for(xi=0;xi<xl;xi++){
		ls[a++]=x[xi];
	}
	free(x);
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
int ITERS=1000;
int NELEMENTS=20;
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
void sortOnce(int NELEMENTS,int x){
	printf("generating...\n");
	item *ls=malloc(NELEMENTS*sizeof(item));
	generate(ls,NELEMENTS,x);
	print(ls,NELEMENTS);
	printf("sorting...\n");
	mymergesort(ls,0,NELEMENTS);
	print(ls,NELEMENTS);
	free(ls);
}
int main(){
	int i;
	for(i=0;i<ITERS;i++){
		printf("Iteration: %d\n",i);
		sortOnce(NELEMENTS,i);
		printf("\n");
	}
	return 0;
}
