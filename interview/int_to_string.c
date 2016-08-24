/*
	Aim: 	Find the first non-repeating character in a string
	Author:	Kashinath chillal
	Date:	7th March 2016
*/
#include <stdio.h>
#define SIZE 26

int main()
{
 unsigned int count[SIZE];
 int position[SIZE];
 
 int i,j;
 for(i=0;i < SIZE; i++)
 {	
	count[i]=0;
	position[i] = -1;
 }
 char str[] = "GEEKSFORGEEKS";
 char *ptr=str;
 while(*ptr != '\0')
 {
	count[*ptr-65]++;
 	if(count[*ptr-65] == 1)
		position[*ptr-65]=ptr-str;
	ptr++;
 }
 for(i=0;i < SIZE; i++)
	printf("%c count is %d position %d \n",i+65,count[i],position[i]); 
 return 0;
}
