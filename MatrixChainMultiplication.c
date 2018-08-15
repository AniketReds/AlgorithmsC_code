#include<stdio.h>
#include<stdlib.h>
#define INFY 999
int s[20][20];
long int m[20][20];
int a[20],p[20];
void MatrixChainOrder(int p[],int n){
	int i,j,l,k;
	long int q;
	for(i=1;i<=n;i++){
		m[i][i]=0;
	}
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j=i+l-1;
			m[i][j]=INFY;
			for(k=i;k<=j-1;k++){
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void Optimal(int i, int j){
	if(i==j)
		printf("A%d",i);
	else{
		printf("(");
		Optimal(i,s[i][j]);
		Optimal(s[i][j]+1,j);
		printf(")");
	}
}
int main(){
	int n,i,k,j;
	printf("Enter the number of matrixes:-");
	scanf("%d",&n);
	for(i=0;i<n*2;i++){
		printf("Value of a[%d]:",i);
		scanf("%d",&a[i]);
	}
	p[0]=a[0];
	k=1;
	for(i=1;i<n*2;i++){
		if(a[i-1]!=a[i]){
			p[k++]=a[i];
		}
	}
	printf("\n");
	for(k=0;k<=n;k++){
		printf("Value of p[%d]:%d\n",k,p[k]);
	}
	printf("\n");
	MatrixChainOrder(p,n);
	printf("The cost Matrix is:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("The S-Matrix is:\n");
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	i=1;
	j=n;
	printf("Optimal Order of Matrix are: \n");
	Optimal(i,j);
	return 0;
}