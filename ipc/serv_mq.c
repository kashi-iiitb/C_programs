#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>
//
#define SERV_MQ "/serv_mq1"
#define CLIENT_MQ "/client_mq1"

#define MAX_MESSAGES 10
#define MAX_SIZE 1024

int is_prime(int num){
    int flag=1;
    for(int i=2; i<num; i++){
	    if(num%i == 0)
		    flag=0;
    }
    return flag;
}

int main(){

	mqd_t serv_mqd,client_mqd;
	char rec_buf[MAX_SIZE+1],send_buf[MAX_SIZE+1];
	int num=0;
	struct mq_attr attr;

	attr.mq_flags = 0;
	attr.mq_maxmsg = MAX_MESSAGES;
	attr.mq_msgsize = MAX_SIZE;
	attr.mq_curmsgs = 0;

	errno=0;
	serv_mqd = mq_open(SERV_MQ, O_RDONLY|O_CREAT,0644,&attr);
	if(serv_mqd==-1){
		//perror(errno);
		printf("Error: %d mq_open(serv_mq)\n",errno);
		exit(1);
	}
	errno=0;
	client_mqd = mq_open(CLIENT_MQ, O_WRONLY);
	if(client_mqd==-1){
		//perror(errno);
		printf("Error:%d mq_open(client_mq)\n",errno);
		exit(1);
	}
	errno=0;
	while(1){
	if(mq_receive(serv_mqd,rec_buf,MAX_SIZE,NULL)==-1){
		printf("Error:%d mq_receive(serv_mq)\n",errno);
		exit(1);
	}
	printf("received %s from client\n",rec_buf);
	sscanf(rec_buf,"%d",&num);
	if(is_prime(num))
	    strncpy(send_buf,"PRIME NUMBER",MAX_SIZE);
	else
	    strncpy(send_buf,"NOT A PRIME NUMBER",MAX_SIZE);
	if(mq_send(client_mqd,send_buf,MAX_SIZE,0)==-1){
		printf("Error:mq_send(client_mq)\n");
		exit(1);
	}
	//sleep(1);
	}
	mq_close(serv_mqd);
	mq_unlink(SERV_MQ);
	

}

