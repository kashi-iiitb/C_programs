/*
	Aim: 	Program to check anagram strings 
	Author:	Kashinath chillal
	Date:	7th March 2016
*/
#include <stdio.h>
#define SIZE 256

int count_chars(int count[],char *str)
{
 char *ptr=str;
	
 while(*ptr != '\0')
 {
	count[*ptr]++;
	ptr++;
 }
}

int main(int argc, char* argv[])
{
 unsigned int count1[SIZE];
 unsigned int count2[SIZE];
 
 int i,j;
 for(i=0;i < SIZE; i++)
 {	
	count1[i]=0;
	count2[i]=0;
 }
 //char str1[] = argv[1];
 //char str2[] = argv[2];
 count_chars(count1,argv[1]);
 count_chars(count2,argv[2]);
 /*char *ptr2=str2;
 while(*ptr2 != '\0')
 {
	count2[*ptr2]++;
	ptr2++;
 }*/
 for(i=0;i < SIZE; i++)
 {
 	if(count1[i] != count2[i])
		break;
//	printf("%c count is %d position %d \n",i+65,count[i],position[i]); 
 }
 if(i != SIZE)
	printf("Strings are not anagram\n");
 else
	printf("Strings are anagram\n");

 return 0;
}
