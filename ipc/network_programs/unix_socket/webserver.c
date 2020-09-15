/*Write a simple program to demonstrate "Unix domain socket"
 * Server: takes the input text and returns the same text twice.
 * client: sends some text message.
 * Date: 14th Sept 2020
 * Author: Kashinath Chillal
 * */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>

#define SOCK_PATH "/tmp/sockpath1"
#define BUF_SIZE 1024

int main(){

	printf("start of main...\n");
	char *str = "Hello Unix Socket!!";
	char buf[BUF_SIZE];
        int sfd=0,cfd=0,port=12345;
	struct sockaddr_un sa,ca;
	socklen_t ca_addr_size;

	memset(&sa,0,sizeof(struct sockaddr_un));
	sa.sun_family=AF_UNIX;
	strncpy(sa.sun_path,SOCK_PATH,sizeof(sa.sun_path)-1);

	sfd = socket(AF_UNIX,SOCK_STREAM,0);
	if(sfd==-1){
			perror("socket() error.");
			exit(1);
	}
	if(bind(sfd,(struct sockaddr*)&sa, sizeof(struct sockaddr_un))==-1){
		perror("bind()");
		exit(1);
	}
	if(listen(sfd,5)==-1){
		perror("listen()");
		exit(1);
	}
	while(1){
		ca_addr_size = sizeof(struct sockaddr_un);
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
	close(cfd);
	} // end of while
	printf("end of main...\n");
	return 0;
}




