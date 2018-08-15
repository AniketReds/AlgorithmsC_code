#include<stdio.h>
#include<stdlib.h>
#define INFY 9999
void msort(int * ,int , int );
void merge(int * ,int , int , int );
int main(){
	int a[1000],i,n,low,high,j;
	printf("How Many Numbers?");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Value of a[%d]:",i);
		scanf("%d",&a[i]);
	}
	low=0;
	high=n;
	msort(a,0,n);
	printf("The Sorted Value:");
	for(j=0;j<n;j++){
		printf("%d\n",a[j]);
	}
	return 0;
}
void msort(int a[],int low,int high){
	int q;
	if(low<high){
		q=((high+low)/2);
		msort(a,low,q);
		msort(a,q+1,high);
		merge(a,low,q,high);
	}
}
void merge(int a[], int p, int q, int r){
	int n1,n2,d,i,j,l[100],k[100];
	n1=q-p+1;
	n2=r-q;
	for(i=1;i<=n1;i++){
		l[i]=a[p+i-1];
	}
	for(j=1;j<=n2;j++){
		k[j]=a[q+j];
	}
	l[n1+1]=INFY;
	k[n2+1]=INFY;
	i=1;
	j=1;
	for(d=p;d<=r;d++){
		if(l[i]<=k[j]){
			a[d]=l[i];
			i++;
		}
		else{
			a[d]=k[j];
			j++;
		}
	}
}