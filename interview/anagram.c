/*
	Aim: 	Program to check anagram strings 
	Author:	Kashinath chillal
	Date:	7th March 2016
*/
#include <stdio.h>
#define SIZE 256

int main()
{
 unsigned int count1[SIZE];
 unsigned int count2[SIZE];
 
 int i,j;
 for(i=0;i < SIZE; i++)
 {	
	count1[i]=0;
	count2[i]=0;
 }
 char str1[] = "GEEKSFORGEEKS";
 char str2[] = "GEEKSFORGEEKS";
 char *ptr1=str1;
 char *ptr2=str2;
 while(*ptr1 != '\0')
 {
	count1[*ptr1]++;
	ptr1++;
 }
 while(*ptr2 != '\0')
 {
	count2[*ptr2]++;
	ptr2++;
 }
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
