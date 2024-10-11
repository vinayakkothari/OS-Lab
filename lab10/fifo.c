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
    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (!contains(frame, m, page[i])) {
            page_fault++;
            frame[pos] = page[i]; 
            pos = (pos + 1) % m; 
        }
    }

    printf("Total page faults: %d\n", page_fault);
    free(frame);
    free(page);
    return 0;
}