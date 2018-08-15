#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int edg;
	struct edge *next;
}q;
typedef struct vertex{
	char vrtx;
	struct edge *link;
}p;
int search(char a,p v[],int b){
	int i;
	for(i=1;i<=b;i++){
		if(v[i].vrtx==a)
			return (i);
	}
}
int main(void){
	p a[20];
	char ch,z;
	q *temp,*current=NULL;
	int n,i,j,x,y;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("\nEnter the Vertex Name: ");
		fflush(stdin);
		scanf("%c",&a[i].vrtx);
		a[i].link=NULL;
	}
	for(i=1;i<=n;i++){
		ch='y';
		printf("\n Any Vertex Connected (Y/N) with %c: ",a[i].vrtx);
		fflush(stdin);
		scanf("%c",&ch);
		while(ch=='y'||ch=='Y'){
			current=(q*)malloc(sizeof(q));
			printf("\nEnter the name of the vertex %c is connected to: ",a[i].vrtx);
			fflush(stdin);
			scanf("%c",&z);
			current->edg=search(z,a,n);
			current->next=NULL;
			if(a[i].link==NULL){
				a[i].link=current;
				temp=current;
			}
			else{
				temp->next=current;
				temp=temp->next;
			}
			printf("\nAny other vertex connected (Y/N): ");
			fflush(stdin);
			scanf("%c",&ch);
		}
	}
	for(i=1;i<=n;i++){
		printf("\n%c->",a[i].vrtx);
		current=a[i].link;
		while(current!=NULL){
			printf("%c",a[current->edg].vrtx);
			if(current->next!=NULL)
				printf(", ");
			current=current->next;
		}
	}
	return 0;
}