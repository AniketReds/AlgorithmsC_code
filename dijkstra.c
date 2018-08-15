#include<stdio.h>
struct vertex{
	int s,w,stat;
}arr[10];
int adj[10][10],W=0,n,cur;
Is_Permanent(){
	int i;
	for(i=1;i<=n;i++){
		if(arr[i].stat==0)
			return 1;
	}
	return 0;
}
void selection(){
	int i,min,pos,cur_wght=0,new_wght,k;
	for(i=1;i<=n;i++){
		arr[i].w=999;
		arr[i].stat=0;
	}
	cur=1;
	arr[cur].stat=1;
	while(Is_Permanent()){
		for(i=1;i<=n;i++){
			if(adj[cur][i]<arr[i].w && arr[i].stat==0){
				new_wght=adj[cur][i]+cur_wght;
				if(new_wght<arr[i].w){
					arr[i].w=new_wght;
					arr[i].s=cur;
				}
			}
		}
		min=999;
			pos=0;
			for(i=1;i<=n;i++){
				if(min>arr[i].w && arr[i].stat==0){
					min=arr[i].w;
					pos=i;
				}
			}
			W=W+min;
			arr[pos].stat=0;
			printf("\nEdge selected %d->%d",arr[pos].s,pos);
			cur=pos;
			cur_wght=min;
			printf("\n");
			for(k=1;k<=n;k++)
				printf(" %d",k);
			printf("\n");
			for(k=1;k<=n;k++)
				printf(" %d",arr[k].w);
	}
}
void main(){
	int i,j;
	printf("Enter the Number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		adj[i][i]=999;
		for(j=i+1;j<=n;j++){
			printf("Enter the weight between %d and %d:",i,j);
			scanf("%d",&adj[i][j]);
			adj[j][i]=adj[i][j];
		}
	}
	selection();
	printf("\nTotal Weight:%d",W);
}