#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

enum states{THINKING,HUNGRY,EATING};
enum states philo_state[5];
int chopsticks[5];
int philosophers_ids[5];

void wait(int *s){
    while(*s<=0);
    (*s)--;
}

void signal(int *s){
    (*s)++;
}

void test(int i){
    if(philo_state[(i+4)%5]!=EATING && philo_state[i]==HUNGRY && philo_state[(i+1)%5]!=EATING){
        philo_state[i]=EATING;
        signal(&chopsticks[i]);
    }
}

void pickup(int i){
    philo_state[i]=HUNGRY;
    test(i);
    if(philo_state[i]!=EATING){
        wait(&chopsticks[i]);
    } 
}

void putdown(int i){
    philo_state[i]=THINKING;
    test((i+4)%5);
    test((i+1)%5);
}

void *philosopher(void *arg) {
    int id = *((int *)arg);
    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 3 + 1); 

        pickup(id);
        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 3 + 1); 

        putdown(id);
    }
    return NULL;
}

int main(){
    int i;
    pthread_t philosophers[5];
    for (i = 0; i < 5; i++) {
        chopsticks[i]=0;
    }
    for(i=0;i<5;i++){
        philo_state[i]=THINKING;
    }

    for (i = 0; i < 5; i++) {
        philosophers_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosophers_ids[i]);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(philosophers[i], NULL);
    }
}