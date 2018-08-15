#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void knapsack(int ,int ,int *,int *);
int max(int,int);
int main(){
	int *w,*p,kp,n,i;
	printf("Enter the Knapsack Capacity:");
	scanf("%d",&kp);
	printf("\n");
	printf("Enter the number of items:");
	scanf("%d",&n);
	printf("\n");
	w=(int*)malloc(n*sizeof(int));
	p=(int*)malloc(n*sizeof(int));
	printf("The Weights are:-");
	printf("\n");
	for(i=1;i<=n;i++){
		printf("Value of w[%d]:",i);
		scanf("%d",&w[i]);
	}
	printf("\n");
	printf("The Profits are:-");
	printf("\n");
	for(i=1;i<=n;i++){
			printf("Value of p[%d]:",i);
			scanf("%d",&p[i]);
	}
	knapsack(n,kp,w,p);
}
void knapsack(int n,int kp,int *a,int *b){
	int v[100][100],i,j,x[100],profit=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=kp;j++){
			if(i==0 || j==0)
				v[i][j]=0;
			else{
				if(j<a[i])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=max(v[i-1][j],(v[i-1][j-a[i]]+b[i]));
			}
		}
	}
	for(i=1;i<=n;i++){
		x[i]=0;
	}
	i=n;
	j=kp;
	while(i>0 && j>0){
		if(v[i][j]!=v[i-1][j]){
			x[i]=1;
			j=j-a[i];
		}
		i--;
	}
	printf("\n");
	printf("The Optimal Set of Weights are:\n");
	for(i=1;i<=n;i++){
		if(x[i]==1){
			printf("\n %d item is taken.",i);
			profit=profit+b[i];
		}
		else{
			printf("\n %d item is not taken.",i);
		}
	}
	printf("\n");
	printf("The Profit is:%d",profit);
}
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}