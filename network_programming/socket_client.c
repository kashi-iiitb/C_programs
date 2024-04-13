#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void main(){
    int sock_fd;
    struct sockaddr_in addr, daddr;
    socklen_t addr_len;

    if((sock_fd=socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Error creating socket()\n");        
    } else {
        printf("success in socket()\n");
    }

    /*addr.sin_family = AF_INET;
    addr.sin_port = htons(2500);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if(bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        printf("Error in bind()\n");        
    } else {
        printf("success in bind()\n");
    }*/
    daddr.sin_family = AF_INET;
    daddr.sin_port = htons(2024);
    //daddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    inet_aton("127.0.0.1", &daddr.sin_addr);

    if(connect(sock_fd, (struct sockaddr *)&daddr, sizeof(daddr)) < 0){
        printf("Error in connect()\n");        
    } else {
        printf("success in connect()\n");
    }

    char str[100] = "Hello";
    write(sock_fd, str, strlen(str)+1);
}