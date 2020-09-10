#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 256

int main(){

	int pipe_fd[2];
	char buf[MAX];
	int status=0;
	pipe(pipe_fd);
	if(fork()==0){
		printf("I am child process\n");
		close(pipe_fd[1]);
		read(pipe_fd[0],buf,MAX);
		exit(0);
	} else{
		printf("I am parent process\n");
		close(pipe_fd[0]);
		write(pipe_fd[1],"Hello World!!",MAX);
		
	}
	printf("waiting for child to finish\n");
	wait(&status);
	printf("child process exited with status %d\n",status);
}
