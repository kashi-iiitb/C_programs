#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>
#include <time.h>
//
#define SERV_MQ "/serv_mq1"
#define CLIENT_MQ "/client_mq1"

#define MAX_SIZE 1024

int main(){

	mqd_t serv_mqd,client_mqd;
	char rec_buf[MAX_SIZE+1],send_buf[MAX_SIZE+1];
	struct mq_attr attr;
	int num=14567;

	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_SIZE;
	attr.mq_curmsgs = 0;
	errno=0;
	client_mqd = mq_open(CLIENT_MQ, O_RDONLY|O_CREAT,0644,&attr);
	if(client_mqd==-1){
		//perror(errno);
		printf("Error:%d mq_open(client_mq)\n",errno);
		exit(1);
	}
	errno=0;
	serv_mqd = mq_open(SERV_MQ, O_WRONLY,0644,NULL);
	if(serv_mqd==-1){
		//perror(errno);
		printf("Error: %d mq_open(serv_mq)\n",errno);
		exit(1);
	}
	srand(time(NULL));
	errno=0;
	while(1){
	//itoa(num,send_buf,10);
	//
	num = rand()%10000;
	snprintf(send_buf,10,"%d",num);
	//strncpy(send_buf,"Hello Kashi!",MAX_SIZE);
	if(mq_send(serv_mqd,send_buf,MAX_SIZE,0)==-1){
		printf("Error:mq_send(serv_mq)\n");
		exit(1);
	}
	errno=0;
	if(mq_receive(client_mqd,rec_buf,MAX_SIZE,0)==-1){
		printf("Error:mq_receive(client_mq)\n");
		exit(1);
	}
	printf("received %s from server\n",rec_buf);
	//sleep(2);
	}
	mq_close(serv_mqd);
	mq_unlink(SERV_MQ);
	

}

