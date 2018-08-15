#include<stdio.h>
int G[10][10],i,j,n,pivot,nval,p[10][10];
void Fllyodwarshall();
int main(void){
	printf("\nEnter the number of nodes:\n");
	scanf("%d",&n);
	printf("\nEnter the Weights:-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("a[%d][%d]:",i,j);
			scanf("%d",&G[i][j]);
		}
	}
	Fllyodwarshall();
	printf("\nShortest Distance between every pair of Vertices:-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",G[i][j]);
		}
		printf("\n");
	}
	printf("\nShortest path between every pair of Vertices are:-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void Fllyodwarshall(){
	for(pivot=0;pivot<n;pivot++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				nval=G[i][pivot]+G[pivot][j];
				if(nval<G[i][j]){
					G[i][j]=nval;
					p[i][j]=pivot;
				}
			}
		}
	}
}