#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fcfs(int *track, int numTracks) {
    int overhead = 0;
    printf("Seek Sequence: %d", track[0]);
    
    for (int i = 1; i < numTracks + 1; i++) {
        printf(" -> %d", track[i]);
        overhead += abs(track[i] - track[i - 1]);
    }
    return overhead;
}

int main() {
    int numTracks, head;

    printf("Enter the number of tracks to be checked: ");
    scanf("%d", &numTracks);

    int *track = (int *)malloc((numTracks + 1) * sizeof(int));
    
    printf("Enter the current head position: ");
    scanf("%d", &head);
    track[0] = head;  // Setting the initial head position 

    printf("Enter the tracks to be checked:\n");
    for (int i = 1; i < numTracks + 1; i++) {
        printf("Track %d: ", i);
        scanf("%d", &track[i]);
    }
  
    int overhead = fcfs(track, numTracks);
    printf("\nTotal Seek Overhead: %d\n", overhead);
    return 0;
}
