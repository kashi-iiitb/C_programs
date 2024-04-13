#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>

#define SERVER_PORT 2024
#define MAX_BUF_SIZE 4096

void* handle_connection(void* c_fd){
    int client_fd = *((int*)c_fd);
    char recv_buf[MAX_BUF_SIZE];
    char send_buf[MAX_BUF_SIZE];

    if(read(client_fd, recv_buf, MAX_BUF_SIZE)<0){
        printf("Error in read()\n");
        //return -1;        
    } else{
        printf("%s\n", recv_buf);
    }
    
    FILE *fd = fopen("socket_server.c", "r");
    if(fd<0){
        printf("Error opening file\n");
        //return -1;
    }
    int num_chars=0;
    memset(send_buf, 0, MAX_BUF_SIZE);
    num_chars = fread(send_buf, 1, MAX_BUF_SIZE-1, fd);

    printf("contents of the send_buf = %s, num_chars=%d",
            send_buf, num_chars);
}

int main(){
    struct sockaddr_in saddr, caddr;
    __socklen_t saddr_len, caddr_len;
    int sock_fd, client_fd;


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
        pthread_t t;
        pthread_create(&t, NULL, handle_connection, &client_fd);

    }

    //handle_connection(&client_fd);



}