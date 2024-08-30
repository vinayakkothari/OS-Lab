#include <stdio.h>
#include <limits.h>

#define MAX 10

// Function prototypes
void preemptiveSJF();
void roundRobin();
void priorityScheduling();
void printGanttChart(int n, int bt[], int at[], int p[], int ct[], int wt[], int tat[], char* algoName);

int main() {
    int choice;

    while (1) {
        printf("\nProcess Scheduling Algorithms\n");
        printf("1. Preemptive SJF\n");
        printf("2. Round Robin\n");
        printf("3. Non-Preemptive Priority Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                preemptiveSJF();
                break;
            case 2:
                roundRobin();
                break;
            case 3:
                priorityScheduling();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

void preemptiveSJF() {
    int n, i, j, t = 0, min, minIndex;
    int bt[MAX], at[MAX], p[MAX], wt[MAX], tat[MAX], ct[MAX], remaining_bt[MAX];
    float avgwt = 0, avgtat = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Arrival Time and Burst Time for process %d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
        remaining_bt[i] = bt[i];
    }

    // Scheduling
    for (t = 0; t < 1000;) { // Arbitrary large time limit
        min = INT_MAX;
        minIndex = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= t && remaining_bt[i] > 0 && remaining_bt[i] < min) {
                min = remaining_bt[i];
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            remaining_bt[minIndex]--;
            t++;
            if (remaining_bt[minIndex] == 0) {
                ct[minIndex] = t;
                tat[minIndex] = ct[minIndex] - at[minIndex];
                wt[minIndex] = tat[minIndex] - bt[minIndex];
                avgwt += wt[minIndex];
                avgtat += tat[minIndex];
            }
        } else {
            t++;
        }
    }

    avgwt /= n;
    avgtat /= n;

    // Print results
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("Average WT: %.2f\n", avgwt);
    printf("Average TAT: %.2f\n", avgtat);

    printGanttChart(n, bt, at, p, ct, wt, tat, "Preemptive SJF");
}

void roundRobin() {
    int n, i, j, quantum, t = 0, remaining;
    int bt[MAX], at[MAX], p[MAX], wt[MAX], tat[MAX], ct[MAX];
    float avgwt = 0, avgtat = 0;
    
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Arrival Time and Burst Time for process %d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int queue[MAX], front = 0, rear = 0;
    int remaining_bt[MAX];
    
    for (i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    queue[rear++] = 0; // Start with process 0

    while (front < rear) {
        int idx = queue[front++];
        if (remaining_bt[idx] > quantum) {
            remaining_bt[idx] -= quantum;
            t += quantum;
            for (i = 0; i < n; i++) {
                if (at[i] <= t && i != idx && remaining_bt[i] > 0) {
                    queue[rear++] = i;
                }
            }
            queue[rear++] = idx;
        } else {
            t += remaining_bt[idx];
            remaining_bt[idx] = 0;
            ct[idx] = t;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            avgwt += wt[idx];
            avgtat += tat[idx];
        }
    }

    avgwt /= n;
    avgtat /= n;

    // Print results
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("Average WT: %.2f\n", avgwt);
    printf("Average TAT: %.2f\n", avgtat);

    printGanttChart(n, bt, at, p, ct, wt, tat, "Round Robin");
}

void priorityScheduling() {
    int n, i, j;
    int bt[MAX], at[MAX], p[MAX], priority[MAX], wt[MAX], tat[MAX], ct[MAX];
    float avgwt = 0, avgtat = 0;
    
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Arrival Time, Burst Time and Priority for process %d: ", i);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
    }
    
    // Sort processes based on priority (higher priority first)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (priority[j] < priority[j + 1]) {
                // Swap Burst Time
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap Arrival Time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap Priority
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap Process Number
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i];
        }
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
        time = ct[i];
    }

    avgwt /= n;
    avgtat /= n;

    // Print results
    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i], at[i], bt[i], priority[i], ct[i], wt[i], tat[i]);
    }
    printf("Average WT: %.2f\n", avgwt);
    printf("Average TAT: %.2f\n", avgtat);

    printGanttChart(n, bt, at, p, ct, wt, tat, "Priority Scheduling");
}

void printGanttChart(int n, int bt[], int at[], int p[], int ct[], int wt[], int tat[], char* algoName) {
    printf("\n%s Gantt Chart:\n", algoName);
    printf("\t+");
    for (int i = 0; i < n; i++) {
        printf("-------+");
    }
    printf("\n\t|");
    for (int i = 0; i < n; i++) {
        printf("   %d   |", p[i]);
    }
    printf("\n\t+");
    for (int i = 0; i < n; i++) {
        printf("-------+");
    }
    printf("\n\t0");
    int lastTime = 0;
    for (int i = 0; i < n; i++) {
        lastTime = ct[i];
        printf("\t%d", lastTime);
    }
    printf("\n");
}
