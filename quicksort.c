#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void quksortsort(int * ,int ,int );
int partition(int * , int ,int );
int main(){
	int n,i,a[10],low,high;
	printf("How many number?");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("value of a[%d]:",i);
		scanf("%d",&a[i]);
	}
	low=0;
	high=n;
	printf("The Sorted value:");
	quksortsort(a,0,n-1);
	for(i=low;i<high;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
void quksortsort(int a[],int low,int high){
	int j;
		if(low<high){
			j=partition(a,low,high);
			quksortsort(a,low,j-1);
			quksortsort(a,j+1,high);
		}
}
int partition(int a[], int p, int q){
	int pivot,i,j,temp,temp1;
	pivot=a[p];
	i=p+1;
	j=q;
	while(i<j){
		while(pivot>a[i]){
			i++;
		}
		while(pivot<a[j]){
			j--;
		}
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp1=a[p];
	a[p]=a[j];
	a[j]=temp1;
	return j;
}
