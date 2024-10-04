#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

void first_fit(int n,int m,int *holes,int *process)
{
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(process[i]<holes[j]){
				holes[j]-=process[i];
				printf("Process %d in hole %d\n",(i+1),(j+1));
				break;
			}
		}
	}	
}

int main()
{
	int n,m,i;
	printf("Enter the number of holes: ");
	scanf("%d",&n);
	printf("Enter the number of process: ");
	scanf("%d",&m);
	int *holes=(int*)malloc(n*sizeof(int));
	printf("Enter the sizes of holes\n");
	for(i=0;i<n;i++){
		scanf("%d",&holes[i]);
	}
	int *process=(int*)malloc(m*sizeof(int));
	printf("Enter the sizes of process\n");
	for(i=0;i<m;i++){
		scanf("%d",&process[i]);
	}
	printf("First fit\n");
	first_fit(n,m,holes,process);

}