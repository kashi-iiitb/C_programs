#include <stdio.h>
#include <pthread.h>

void print_ulong(unsigned long num){
    for(unsigned long i=0; i<num; i++){
     
    }
}
void* print_ulong_thread(void* arg){
    for(__uint8_t i=0; i<50; i++ ){
        for(unsigned long i=0; i<*((unsigned long *)arg); i++){
        }
    }
}

int main(){
    pthread_t t;
    unsigned long num = 100000000UL;
    pthread_create(&t, NULL, print_ulong_thread, &num);
    for(__uint8_t i=0; i<100; i++ )
        print_ulong(num);
    pthread_join(t, NULL);
}