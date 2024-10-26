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

int look(int *track, int n, int head, int dir) {
    int overhead = 0;
    int index = -1;

    track[n] = head;
    sort(track, n + 1);

    for (int i = 0; i < n + 1; i++) {
        if (track[i] == head) {
            index = i;
            break;
        }
    }

    printf("Seek Sequence: %d", head);

    if (dir == 1) {
        for (int i = index + 1; i < n + 1; i++) { //rightwards movement (head to end)
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
        
        for (int i = index - 1; i >= 0; i--) { //leftwards movement (to the start after reaching the end)
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
    } else {
        for (int i = index - 1; i >= 0; i--) { //leftwards movement (head to beginning)
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
        
        for (int i = index + 1; i < n + 1; i++) { //rightwards movement to the end of the array after reaching the start
            overhead += abs(track[i] - head);
            head = track[i];
            printf(" -> %d", head);
        }
    }

    return overhead;
}

int main() {
    int n, head, dir;

    printf("Enter the number of tracks to be checked: ");
    scanf("%d", &n);

    int *track = (int*)malloc((n + 1) * sizeof(int));

    printf("Enter the current head position: ");
    scanf("%d", &head);

    printf("Enter the tracks to be checked:\n");
    for (int i = 0; i < n; i++) {
        printf("Track %d: ", i + 1);
        scanf("%d", &track[i]);
    }
    
    printf("Enter the initial direction of movement (-1 for left, 1 for right): ");
    scanf("%d", &dir);

    int overhead = look(track, n, head, dir);
    printf("\nTotal Seek Overhead: %d\n", overhead);

    return 0;
}
