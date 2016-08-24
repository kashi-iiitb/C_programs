/**************************************************
This program demonstartes the use of debug macros

Author: Kashinath Chillal
Date: 5th Aug 2016

**************************************************/


#include <stdio.h>
#include <time.h>
#include "debug.h"

#define BUFFERSIZE 4096

int oops(char* s1, char* s2)
{
  fprintf(stderr,"Error: %s",s1);
  perror(s2);
}

int file_copy(char* src, char* dest)
{ 
 char buf[BUFFERSIZE];
 FILE* in_fd,*out_fd;
 int num;
 char ch;
 
 if( (in_fd = fopen(src,"r")) == NULL){
 	//perror("Can not open input file: ");
 	debug("Can not open input file: ");
 	exit(1);
 }
 if( (out_fd = fopen(dest,"w")) == NULL){
 	debug("Can not open output file: ");
	exit(1);
 }
 //close(argv[1]);
 while((ch = fgetc(in_fd))!=EOF)
 {
	fputc(ch,out_fd);
 }
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
 printf("Time required"" to copy the file = %dsec\n",time_to_copy);
 return 0;
}


