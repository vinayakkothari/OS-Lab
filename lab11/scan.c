#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void sort(int *track, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (track[j] > track[j + 1]) {
                int temp = track[j];
                track[j] = track[j + 1];
                track[j + 1] = temp;
            }
        }
    }
}

int scan(int *track, int n, int head, int dir) {
    int overhead = 0;
    int index = -1;

    track[n] = 0;      // Lower bound
    track[n + 1] = 199; // Upper bound
    track[n + 2] = head;
    sort(track, n + 3);

    for (int i = 0; i < n + 3; i++) {
        if (track[i] == head) {
            index = i;
            break;
        }
    }

    printf("Seek Sequence: %d", head);

    if (dir == 1) { // Moving towards the right/upwards
        for (int i = index + 1; i < n + 3; i++) {
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
        // After reaching the end, moving left/downwards
        for (int i = index - 1; i >= 0; i--) {
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
    } else { // Moving towards the left/downwards
        for (int i = index - 1; i >= 0; i--) {
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
        // After reaching the start, moving right/upwards
        for (int i = index + 1; i < n + 3; i++) {
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
    }

    return overhead;
}

int main() {
    int n, head;
    printf("Enter the number of tracks to be checked: ");
    scanf("%d", &n);

    int *track = (int *)malloc((n + 3) * sizeof(int));

    printf("Enter the current head position: ");
    scanf("%d", &head);

    printf("Enter the tracks to be checked:\n");
    for (int i = 0; i < n; i++) {
        printf("Track %d: ", i + 1);
        scanf("%d", &track[i]);
    }

    int dir;
    printf("Enter the initial direction of movement (-1 for left, 1 for right): ");
    scanf("%d", &dir);
    
    int overhead = scan(track, n, head, dir);
    printf("\nTotal Seek Overhead: %d\n", overhead);

    return 0;
}
