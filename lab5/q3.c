#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void bubble(char *arr[], int n) {
  int i,j;
  for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
}


void selection(char *arr[], int n) {
    int i,j;
    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        char *temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    for(i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
}

int main(){
    int N,i;
    printf("Enter the number of strings:\n ");
    scanf("%d", &N);
    char **strings = (char **)malloc(N * sizeof(char *));
    printf("Enter %d strings:\n", N);
    for (i = 0; i < N; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char));
        printf("String %d: ", i + 1);
        scanf("%s", strings[i]);
    }
    pid_t pid1;
    pid_t pid2;
    int status;
    pid1=fork();
    if (pid1 == 0) {
        printf("First child: Bubble sort\n");
        bubble(strings,N);
        exit(0);
    } else if (pid1 > 0) {
        pid2 = fork();
        if (pid2 == 0) {
            printf("Second child: Selection sort\n");
            selection(strings,N);
            exit(0);
        } else if (pid2 > 0) {
            wait(&status);
            printf("\nParent: Child process terminated\n");
        } else {
            printf("Error");
        }
    } else {
        printf("Error");
    }
}
