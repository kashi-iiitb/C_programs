#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#include <pthread.h>
#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BACKLOG 5
#define BUF_MAX_SIZE 100

int main(){
    int sock_fd, client_sock_fd;
    struct sockaddr_in addr, client_addr;
    int client_addr_len=0;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(2024);
    //addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //addr.sin_addr.s_addr = inet_addr("192.168.0.1");
    //inet_aton("192.168.0.1", &addr.sin_addr);

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        printf("Error creating socket.\n");
        return -1;
    } else
        printf("socket() success\n");

    if(bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1){
        printf("Error in bind()\n");
        return -1;
    } else
        printf("bind() success\n");

    if(listen(sock_fd, MAX_BACKLOG) < 0){
        printf("Error in listen()\n");
        return -1;
    } else
        printf("listen() success\n");

    client_addr_len = sizeof(client_addr);
    if((client_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr,
                                &client_addr_len)) < 0){
        printf("Error in accept()\n");
        return -1;
    } else
        printf("accept() success\n");

    char buf[BUF_MAX_SIZE];
    memset(buf, 0, BUF_MAX_SIZE);
    read(client_sock_fd, buf, BUF_MAX_SIZE);
    printf("\n%s\n",buf);
    
}