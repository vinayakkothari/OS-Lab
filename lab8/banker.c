#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //input the resources and processes
	int m,n,i,j;
	printf("Enter the number of processes");
	scanf("%d",&m);
	printf("Enter the number of resources");
	scanf("%d",&n);

	int *available = (int*)malloc(n*sizeof(int));
	bool *completed= (bool*)malloc(m*sizeof(bool));
	int** max = (int**)malloc(m * sizeof(int*));
	int** allocation = (int**)malloc(m * sizeof(int*));
	int** need = (int**)malloc(m * sizeof(int*));	
    	for (i = 0; i < n; i++){
		max[i] = (int*)malloc(n * sizeof(int));
		allocation[i] = (int*)malloc(n * sizeof(int));
		need[i] = (int*)malloc(n * sizeof(int));		
	}
    
    printf("Enter the available resources:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources each process can claim:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (i = 0; i < m; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
        completed[i] = false;
    }
	bool safe = true;
int completed_no = 0;

while (completed_no < m) {
    bool found = false;
    
    for (int i = 0; i < m; i++) {
        if (!completed[i]) { 
            bool canExecute = true;
            for (int j = 0; j < n; j++) {
                if (need[i][j] > available[j]) { 
                    canExecute = false;
                    break;
                }
            }
            if (canExecute) { 
                found = true;
                printf("Process %d is executing\n", i);
                for (int j = 0; j < n; j++) {
                    available[j] += allocation[i][j]; 
                }
                completed[i] = true; 
                completed_no++; 
                break; 
            }
        }
    }

    if (!found) { 
        safe = false;
        break;
    }
}

if (safe) {
    printf("Safe sequence\n");
} else {
    printf("Unsafe sequence\n");
}

}