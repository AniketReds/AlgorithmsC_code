#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nqueens(int [],int,int);
int check(int [],int,int);
void display(int[]);
int n;
int main(void){
	int n,i,j,s[10];
	printf("Enter the number of queens: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		s[i]=0;
	}
	printf("\nHow Many feasible solutions:");
	scanf("%d",&j);
	printf("\n Enter Solutions:-");
	for(i=1;i<=j;i++){
		scanf("%d",&s[i]);
	}
	nqueens(s,j+1,0);
}
void nqueens(int a[],int row,int col){
	int i,flag=0;
	for(i=1;i<row;i++)
		printf("%d ",a[i]);
	printf("\n");
	if(row>n){
		printf("\n\n\n\n");
		display(a);
		return;
	}
	for(i=col+1;i<=n;i++){
		if(check(a,row,i)){
			flag=1;
			a[row]=i;
			break;
		}
	}
	if(flag!=1){
		a[row]=0;
		nqueens(a,row-1,a[row-1]);
	}
	else
		nqueens(a,row+1,0);
}
int check(int a[],int r,int c){
	int i;
	for(i=1;i<r;i++){
		if(a[i]==c)
			return 0;
	}
	for(i=1;i<r;i++){
		if((a[i]+i==r+c) || (a[i]-i==c-r))
			return 0;
		}
	return 1;
}
void display(int a[]){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i]==j)
				printf("Q ");
			else
				printf("- ");
		}
		printf("\n");
	}
}