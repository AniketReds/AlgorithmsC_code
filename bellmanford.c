#include<stdio.h>
#include<stdlib.h>
int main(void){
	int V,edge[20][2],G[20][20],i,j,k=0;
	printf("\nEnter the number of vertices:-");
	scanf("%d",&V);
	printf("Enter the graph in matrix form:\n");
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]!=0){
				edge[k][0]=i;
				edge[k++][1]=j;
			}
		}
	}
	if(Bellman_ford(G,V,k,edge))
		printf("\nNo Negative Weight Cycles\n");
	else
		printf("\nNegative Weight Cycles Exists\n");
	return 0;
}
int Bellman_ford(int G[20][20],int V,int E,int edge[20][2]){
	int i,u,v,k,dist[20],par[20],S,flag=1;
	for(i=0;i<V;i++){
		dist[i]=1000;
		par[i]=-1;
	}
	printf("\nEnter the Source:");
	scanf("%d",&S);
	dist[S-1]=0;
	for(i=0;i<V-1;i++){
		for(k=0;k<E;k++){
			u=edge[k][0];
			v=edge[k][1];
			if(dist[u]+G[u][v]<dist[v]){
				dist[v]=dist[u]+G[u][v];
				par[v]=u;
			}
		}
	}
	for(k=0;k<E;k++){
		u=edge[k][0];
		v=edge[k][1];
		if(dist[u]+G[u][v]<dist[v])
			flag=0;
	}
	if(flag){
		for(i=0;i<V;i++)
			printf("Vertex %d->cost=%d parent=%d\n",i+1,dist[i],par[i]+1);
	}
	return flag;
}