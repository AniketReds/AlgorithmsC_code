/*
4
2
1 2
2
2 3
2
1 2
1
1
*/
#include<stdio.h>
#include<malloc.h>

typedef struct graph
{
	int vertex;
	//int weight;
	struct graph *next;
}node;
void createGraph(node *adjacent[],int n)
{
	int i = 0;
	for(i = 0;i < n;i++)
	{
		adjacent[i] = NULL;
	}
}
void display(node *adjacent[],int n)
{
	node *p = NULL;
	int i = 0;
	for(i = 0;i < n;i++)
	{
		p = adjacent[i];
		printf("Vertex %d : ",i);
		if(p == NULL)
			printf("Empty");
		while(p != NULL)
		{
			printf("%d -> ",p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}
void displayNode(node *head)
{
	node *temp = head;
	if(head == NULL)
	{
		printf("List is empty");
		return;
	}
	for(; temp != NULL; temp = temp->next)
		printf("%d ->",temp->vertex);
}
/*void insertend(node *head,int data)
{
	node *p = NULL, *temp = NULL;
	p = (node *)malloc(sizeof(node));

	p->vertex = data;
	p->next = NULL;

	if(head == NULL)
	{
		head = p;
		return;
	}
	// to loop over to the end
	for(temp = head;temp->next != NULL; temp = temp->next);

	temp->next = p;
	//displayNode(head);
}*/
void insert(node *adjacent[],int n)
{
	int i = 0,j = 0,num = 0,item = 0;
	node *p = NULL,*temp = NULL;
	for(i = 0;i < n;i++)
	{
		printf("Enter the no of edges");
		scanf("%d",&num);
		for(j = 0;j < num;j++)
		{
			scanf("%d",&item);
			//insertend(adjacent[i],item);
			p = (node *)malloc(sizeof(node));

			p->vertex = item;
			p->next = NULL;

			if(adjacent[i] == NULL)
			{
				adjacent[i] =  p;	
				continue;
			}
			// to loop over to the end
			for(temp = adjacent[i];temp->next != NULL; temp = temp->next);

			temp->next = p;
			//displayNode(adjacent[i]);
		}
	}
}
int main(void)
{
	int n = 0,i = 0,j = 0,ch = 0;
	printf("Enter the no of vertices");
	scanf("%d",&n);
	node *adjacent[n];
	createGraph(adjacent,n);
	display(adjacent,n);
	insert(adjacent,n);
	display(adjacent,n);
	return 0;
}