/*
This program will update the existing multithreaded server.
Instead of creating a thread each time for new client, we will have a pre-existing
pool of threads. Whenver a new client connects, one of the free thread will pick up
the task for the newly connected client.

1. A queue will be maintained for the newly connected clients which needs to be serviced.
queue becomes critical resource and hence, requires mutex while free threads are trying
to access the queue of newly connected clients (client_fds).
2. To avoid free threads busy waiting for the clients to arrive, we will use condition variable
for the new client to be available. Hence, avoiding busy-wait.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>
#include "queue.h"

#define SERVER_PORT 2024
#define MAX_BUF_SIZE 4096
#define MAX_THREADS 50
sem_t sem_nthreads;
pthread_mutex_t q_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;
Queue q = {.front=NULL, .rear=NULL};


void* handle_connection(void* arg){
    
    char recv_buf[MAX_BUF_SIZE];
    char send_buf[MAX_BUF_SIZE];

    /*if(read(client_fd, recv_buf, MAX_BUF_SIZE)<0){
        printf("Error in read()\n");
        //return -1;        
    } else{
        //printf("%s\n", recv_buf);
    }*/
    while(1){
        int client_fd;
        pthread_mutex_lock(&q_mutex);
        
        if((client_fd = dequeue(&q))==-1){
            pthread_cond_wait(&cond_var, &q_mutex);
            client_fd = dequeue(&q);
        }
        pthread_mutex_unlock(&q_mutex);
        if(client_fd!=-1) {
            printf("handling client_fd=%d\n", client_fd);
            if(read(client_fd, recv_buf, MAX_BUF_SIZE)<0){
                printf("Error in read()\n");
                return NULL;        
            }
            //free(client_fd);
        }
        
    }
    
    /*FILE *fp = fopen("big.txt", "r");
    if(fp<0){
        printf("Error opening file\n");
        //return -1;
    }
    //sleep(10);
    int num_chars=0;   
    memset(send_buf, 0, MAX_BUF_SIZE);
    while((num_chars = fread(send_buf, 1, MAX_BUF_SIZE-1, fp)) >0) {
        //printf("Next send:\ncontents of the send_buf = %s, num_chars=%d",
        //        send_buf, num_chars);
        //printf("\nnum_chars=%d\n", num_chars);
        //printf("%s", send_buf);
        memset(send_buf, 0, MAX_BUF_SIZE);
    }
    //printf("\nAt the end num_chars=%d\n", num_chars);
    //printf("post: client connection count=%d\n",num_threads);
    fclose(fp);*/
}

int main(){
    struct sockaddr_in saddr, caddr;
    __socklen_t saddr_len, caddr_len;
    int sock_fd, client_fd;
    unsigned int num_threads=MAX_THREADS;
    pthread_t t[MAX_THREADS];

    for(short i=0; i<50; i++){
        pthread_create(&t[i], NULL, handle_connection, NULL);        
    }

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Error in socket()\n");
        return -1;
    }
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(SERVER_PORT);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock_fd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0){
        printf("Error in bind()\n");
        return -1;
    }
    if(listen(sock_fd, 100) < 0){
        printf("Error in listen()\n");
        return -1;
    }

    
    while(1) {
        if((client_fd = accept(sock_fd, (struct sockaddr *)&caddr, &caddr_len)) < 0){
            printf("Error in accept()\n");
            return -1;
        }
        //printf("accept client_fd=%d\n", client_fd);
        //int *c_fd = malloc(sizeof(int));
        //*c_fd = client_fd;
        pthread_mutex_lock(&q_mutex);        
        enqueue(&q, client_fd);
        pthread_cond_signal(&cond_var);
        pthread_mutex_unlock(&q_mutex);
    }

    //handle_connection(&client_fd);



}