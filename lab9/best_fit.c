#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

void best_fit(int n, int m, int *holes, int *process)
{
    int i, j;
    int min, minfit;
    for(i=0;i<m;i++){
        minfit=INT_MAX;
        min=0;
        for(j=0;j<n;j++){
            if(process[i]<holes[j] && holes[j]-process[i]<minfit){
                min=j;
                minfit=holes[j]-process[i];
            }
        }
        if(minfit != INT_MAX){
            holes[min]-=process[i];
            printf("Process %d in hole %d\n",(i+1),(min+1));
        }
        for(j=0;j<n;j++){
            printf("Hole %d: %d",j,holes[j]);
        }
    }
}

int main()
{
    int n,m,i;
    printf("Enter number of holes: ");
    scanf("%d",&n);
    printf("Enter number of processes: ");
    scanf("%d", &m);
    int *holes=(int*)malloc(n*sizeof(int));
    printf("Enter the sizes of holes:\n");
    for (i=0;i<n;i++){
        scanf("%d", &holes[i]);
    }
    int *process=(int*)malloc(n*sizeof(int));
    printf("Enter the sizes of processes:\n");
    for (i=0;i<m;i++){
        scanf("%d", &process[i]);
    }
    printf("Best Fit: \n");
    best_fit(n,m,holes,process);
}