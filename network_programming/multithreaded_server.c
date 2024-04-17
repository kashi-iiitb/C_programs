#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>

#define SERVER_PORT 2024
#define MAX_BUF_SIZE 4096
sem_t sem_nthreads;


void* handle_connection(void* c_fd){
    int client_fd = *((int*)c_fd);
    char recv_buf[MAX_BUF_SIZE];
    char send_buf[MAX_BUF_SIZE];

    if(read(client_fd, recv_buf, MAX_BUF_SIZE)<0){
        printf("Error in read()\n");
        //return -1;        
    } else{
        //printf("%s\n", recv_buf);
    }
    
    FILE *fp = fopen("big.txt", "r");
    if(fp<0){
        printf("Error opening file\n");
        //return -1;
    }
    sleep(10);
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
    sem_post(&sem_nthreads);
    fclose(fp);
}

int main(){
    struct sockaddr_in saddr, caddr;
    __socklen_t saddr_len, caddr_len;
    int sock_fd, client_fd;
    unsigned int num_threads=0;

    sem_init(&sem_nthreads, 0, 50);

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
    if(listen(sock_fd, 10) < 0){
        printf("Error in listen()\n");
        return -1;
    }

    
    while(1) {
        if((client_fd = accept(sock_fd, (struct sockaddr *)&caddr, &caddr_len)) < 0){
            printf("Error in accept()\n");
            return -1;
        }
        //num_threads++;
        //printf("wait: client connection count=%d\n",num_threads);
        sem_getvalue(&sem_nthreads, &num_threads);
        printf("Num of threads=%u\n", 50-num_threads);
        sem_wait(&sem_nthreads);
        pthread_t t;
        pthread_create(&t, NULL, handle_connection, &client_fd);
        //pthread_join(t, NULL);
    }

    //handle_connection(&client_fd);



}