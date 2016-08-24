/**************************************************

This program is to copy a file from source to destination.
use: ./dir_copy src_file dest_file

Author: Kashinath Chillal
Date: 6th March 2016

**************************************************/


#include <stdio.h>
#include <fcntl.h>
#include <time.h>

#define BUFFERSIZE 4096

int oops(char* s1, char* s2)
{
  fprintf(stderr,"Error: %s",s1);
  perror(s2);
}

int file_copy(char* src, char* dest)
{ 
 char buf[BUFFERSIZE];
 int in_fd,out_fd;
 int num;
 
 if( (in_fd = open(src,O_RDONLY)) == -1)
 	oops("Can not open file: ",src);
 if( (out_fd = open(dest,O_CREAT|O_TRUNC|O_WRONLY)) == -1)
 	oops("Can not create file: ",dest);
 //close(argv[1]);
 while((num = read(in_fd,buf,BUFFERSIZE))>0)
	if(write(out_fd,buf,num) != num)
	  oops("Can not write to file: ", dest);
 close(in_fd);
 close(out_fd);
  
}

int main(int argc, char* argv[])
{
 time_t start_time, end_time;
 int time_to_copy=0;
 printf("Source file name %s\n",argv[1]);
 printf("Destination file name %s\n",argv[2]);
 
 time(&start_time) ;
 file_copy(argv[1],argv[2]);
 time(&end_time);
 time_to_copy = end_time - start_time;
 printf("Time required to copy the file = %dsec\n",time_to_copy);
 return 0;
}


