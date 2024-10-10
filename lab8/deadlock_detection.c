#include <stdio.h>
#include <stdbool.h>

// Function to detect if deadlock is present
bool isDeadlock(int n, int m, int Available[], int Allocation[][10], int Need[][10]) {
    bool Finish[10] = {0}; // To check if process has finished
    int Work[10]; // Temporary work vector
    for (int i = 0; i < m; i++) {
        Work[i] = Available[i]; // Initially, Work is the Available resources
    }
    
    // Try to find a safe sequence
    bool deadlock = true;
    for (int k = 0; k < n; k++) { // We loop n times for all processes
        deadlock = true;
        for (int i = 0; i < n; i++) {
            if (!Finish[i]) { // If process is not finished
                bool canProceed = true;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Work[j]) { // Check if process needs more than available
                        canProceed = false;
                        break;
                    }
                }
                if (canProceed) {
                    // Process can be finished, simulate releasing its resources
                    for (int j = 0; j < m; j++) {
                        Work[j] += Allocation[i][j]; // Release resources
                    }
                    Finish[i] = true; // Mark process as finished
                    deadlock = false; // A process finished, so not a deadlock in this iteration
                    break;
                }
            }
        }
        if (deadlock) break; // If no process can proceed, deadlock is present
    }

    for (int i = 0; i < n; i++) {
        if (!Finish[i]) {
            return true; // Deadlock found, since some processes could not finish
        }
    }
    return false; // No deadlock
}

int main() {
    int n, m;
    int Available[10], Max[10][10], Allocation[10][10], Need[10][10];

    // Input number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    // Input Available resources
    printf("Enter Available resources for each type: \n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    // Input Allocation and Max matrices
    printf("Enter Allocation Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Max Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    // Calculate Need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Perform deadlock detection
    if (isDeadlock(n, m, Available, Allocation, Need)) {
        printf("System is in deadlock.\n");
    } else {
        printf("No deadlock detected.\n");
    }

    return 0;
}
