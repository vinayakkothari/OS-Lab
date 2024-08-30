#include <stdio.h>

int b[10], no[10], wt[10], ta[10], st;

void main() {
    int i, j, n, temp;
    float avgw, tw = 0, tt = 0, avgt;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        no[i] = i;
    }

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                temp = no[j];
                no[j] = no[j + 1];
                no[j + 1] = temp;
            }
        }
    }

    wt[0] = 0; 
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += b[j];
        }
    }

    for (i = 0; i < n; i++) {
        ta[i] = b[i] + wt[i];
        tw += wt[i];
        tt += ta[i];
    }

    avgw = (float)tw / n;
    avgt = (float)tt / n;

    printf("\n\tGantt Chart:\n");
    printf("\t+");
    for (i = 0; i < n; i++) {
        printf("-------+");
    }
    printf("\n\t|");
    for (i = 0; i < n; i++) {
        printf("   %d   |", no[i]);
    }
    printf("\n\t+");
    for (i = 0; i < n; i++) {
        printf("-------+");
    }
    printf("\n\t0");
    int c = 0;
    for (i = 0; i < n; i++) {
        c += b[i];
        printf("\t%d", c);
    }
    printf("\n\n");

    printf("\tP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t%d\t%d\t%d\n", no[i], b[i], wt[i], ta[i]);
    }

    printf("\nAverage WT is %.2f\n", avgw);
    printf("Average TAT is %.2f\n", avgt);
}
