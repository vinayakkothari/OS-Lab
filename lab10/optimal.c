#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool contains(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

int findOptimal(int frame[], int m, int ref[], int n, int x) {
    int opt_index = -1, farthest = -1;
    for (int i = 0; i < m; i++) {
        int j;
        for (j = x + 1; j < n; j++) {
            if (frame[i] == ref[j]) {
                if (j > farthest) {
                    farthest = j;
                    opt_index = i;
                }
                break;
            }
        }
        if (j == n) 
            return i;
    }
    return (opt_index == -1) ? 0 : opt_index;
}

int main() {
    int m, n;
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int* frame = (int*)malloc(m * sizeof(int));
    int* page = (int*)malloc(n * sizeof(int));
    printf("Enter the page references:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    for (int i = 0; i < m; i++) {
        frame[i] = -1; 
    }

    int page_fault = 0;

    for (int i = 0; i < n; i++) {
        if (!contains(frame, m, page[i])) {
            int pos = findOptimal(frame, m, page, n, i);
            frame[pos] = page[i];
            page_fault++;
        }
    }

    printf("Total page faults: %d\n", page_fault);
    free(frame);
    free(page);
    return 0;
}


//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1