#include<stdio.h>
#include<stdlib.h>
void sorting(int,int *,int *,float *);
float knapsack(int,int *,int *);
int main(void){
	int kp,*w,*p,n,i;
	float *pw,profit;
	printf("Enter the number of items:");
	scanf("%d",&n);
	w=(int*)malloc(n*sizeof(int));
	p=(int*)malloc(n*sizeof(int));
	pw=(float*)malloc(n*sizeof(float));
	printf("\n");
	printf("Enter the knapsack Capacity:");
	scanf("%d",&kp);
	printf("\n");
	for(i=1;i<=n;i++){
		printf("Weight of w[%d]:",i);
		scanf("%d",&w[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("Profit of p[%d]:",i);
		scanf("%d",&p[i]);
	}
	for(i=1;i<=n;i++){
		pw[i]=(float)p[i]/w[i];
	}
	printf("\n");
	printf("Item no. Weight  Profit  Profit/Weight\n");
	sorting(n,w,p,pw);
	for(i=1;i<=n;i++){
		printf("%d         %d         %d         %f",i,w[i],p[i],pw[i]);
		printf("\n");
	}
	profit=knapsack(kp,w,p);
	printf("\nThe Profit is:%f",profit);
}
void sorting(int n,int *a,int *b,float *c){
	int i,j,temp1;
	float temp;
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			if(c[j]<c[j+1]){
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
				
				temp1=a[j];
				a[j]=a[j+1];
				a[j+1]=temp1;
				
				temp1=b[j];
				b[j]=b[j+1];
				b[j+1]=temp1;
			}
		}
	}
}
float knapsack(int kp,int *w,int *p){
	int i;
	float profit=0.0;
	i=1;
	while(kp!=0){
		if(kp>w[i]){
			printf("\n %d item is taken as a whole.",i);
			profit=profit+p[i];
			kp=kp-w[i];
		}
		else{
			printf("\n %d item is taken as a part.",i);
			profit=profit+(((float)kp/w[i])*p[i]);
			kp=0;
		}
		i++;
	}
	return profit;
}