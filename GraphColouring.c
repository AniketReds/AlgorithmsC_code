#include<stdio.h>
int G[10][10],m,edges,colour_tab[10],v1,v2,n,i,j,a,b;
void Gen_Col_Value(int,int);
void Gr_colouring(int,int);
int main(void){
	printf("\nEnter the number of nodes and edges:\n");
	scanf("%d %d",&n,&edges);
	m=n-1;
	printf("\n Enter the edges of the graph:-\n");
	for(i=1;i<=edges;i++){
		printf("Enter the value of x and y:\n");
		scanf("%d %d",&v1,&v2);
		G[v1][v2]=G[v2][v1]=1;
		printf("\n");
	}
	Gr_colouring(1,n);
	printf("\n The vertices to be coloured as:\n");
	for(i=1;i<=n;i++){
		printf("\n v%d:=%d",i,colour_tab[i]);
	}
	return 0;
}
void Gr_colouring(int k,int n){
	Gen_Col_Value(k,n);
	if(colour_tab[k]==0)
		return;
	if(k==n)
		return;
	else
		Gr_colouring(k+1,n);
}
void Gen_Col_Value(int k,int n){
	while(1){
		a=colour_tab[k]+1;
		b=m+1;
		colour_tab[k]=a%b;
		if(colour_tab[k]==0)
			return;
		for(j=1;j<=n;j++){
			if(G[k][j]!=0 && colour_tab[k]==colour_tab[j])
				break;
		}
		if(j==n+1)
			return;
	}
}