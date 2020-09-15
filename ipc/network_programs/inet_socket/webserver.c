/*Write a simple program to demonstrate "Internet socket"
 * Server: Sends "Hello" text always when client connects
 * client: connects and displays the data sent from server
 * Date: 15th Sept 2020
 * Author: Kashinath Chillal
 * */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

#define IP_ADDR "127.0.0.1"
#define BUF_SIZE 1024

int main(){

	printf("start of main...\n");
	char *str = "Hello Unix Socket!!";
	char buf[BUF_SIZE];
        int sfd=0,cfd=0,port=12345;
	struct sockaddr_in sa,ca;
	socklen_t ca_addr_size;

	memset(&sa,0,sizeof(struct sockaddr_in));
	sa.sin_family=AF_INET;
	sa.sin_port=htons(port);
	sa.sin_addr.s_addr=INADDR_ANY;
	//inet_aton(IP_ADDR,&sa.sin_addr.s_addr);
//	strncpy(sa.sa_data,IP_ADDR,sizeof(sa.sa_path)-1);

	sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1){
			perror("socket() error.");
			exit(1);
	}
	if(bind(sfd,(struct sockaddr*)&sa, sizeof(struct sockaddr_in))==-1){
		perror("bind()");
		exit(1);
	}
	if(listen(sfd,5)==-1){
		perror("listen()");
		exit(1);
	}
	while(1){
	ca_addr_size = sizeof(struct sockaddr);
	if((cfd=accept(sfd, (struct sockaddr*)&ca, &ca_addr_size))==-1){
		perror("accept()");
		exit(1);
	}
	printf("client connected");
	memset(&buf,0,BUF_SIZE);
	if(read(cfd,buf,BUF_SIZE)==-1){
		perror("read");
		exit(1);
	}
		printf("received %s from client\n",buf);
	snprintf(buf,sizeof(buf),"HTTP/1.0 200 OK\r\n\r\nHello");
	write(cfd,buf,strlen(buf));

	close(cfd);
	} // end of while
	printf("end of main...\n");
	return 0;
}




