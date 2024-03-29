#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
//#include <sys/wait.h>

__uint8_t val = 1;
sem_t sem_even, sem_odd;

void* print_even(void* arg){
    for(__uint8_t i=0; i<5; i++){
        sem_wait(&sem_even);
        printf("%d\n", val++);
        sem_post(&sem_odd);
    }
}
int main(){
    pthread_t t_even;
    pthread_create(&t_even, NULL, print_even, NULL);
    sem_init(&sem_even, 0, 1);
    sem_init(&sem_odd, 0, 0);
    printf("\n");
    for(__uint8_t i=0; i<5; i++){
        sem_wait(&sem_odd);
        printf("%d\n", val++);
        sem_post(&sem_even);
    }
    pthread_join(t_even, NULL);
}