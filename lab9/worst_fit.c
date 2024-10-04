#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void worst_fit(int n, int m, int *holes, int *process) {
    int i, j;
    int max, maxfit;

    for (i = 0; i < m; i++) {
        maxfit = INT_MIN;
        max = -1;  // Start with -1 to indicate no suitable hole found

        // Find the worst fit
        for (j = 0; j < n; j++) {
            if (process[i] <= holes[j] && holes[j] - process[i] > maxfit) {
                max = j;
                maxfit = holes[j] - process[i];
            }
        }

        // Allocate if a suitable hole is found
        if (max != -1) {
            holes[max] -= process[i];
            printf("Process %d allocated in hole %d\n", (i + 1), (max + 1));
        } else {
            printf("Process %d waiting for compaction\n", (i + 1));
        }
    }
}

int main() {
    int n, m, i;
    
    printf("Enter the number of holes: ");
    scanf("%d", &n);
    
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    
    int *holes = (int *)malloc(n * sizeof(int));
    printf("Enter the sizes of holes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &holes[i]);
    }
    
    int *process = (int *)malloc(m * sizeof(int));
    printf("Enter the sizes of processes:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &process[i]);
    }

    printf("Worst Fit Memory Allocation:\n");
    worst_fit(n, m, holes, process);

    // Free dynamically allocated memory
    free(holes);
    free(process);

    return 0;
}
