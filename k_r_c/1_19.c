/*
Reverse the string
*/
#include <stdio.h>
#define  MAX_SIZE 30

int rev_str(char str[]);

int main()
{
  char str[MAX_SIZE] = "Hello World!";
  char to[MAX_SIZE];
  printf("Original string: %s\n",str);
  rev_str(str);
  printf("After reversal the string: %s\n",str);
  return 0;
}

int rev_str(char str[])
{
  int i=0;
  int j=0;
  char temp;
  while(str[j]!='\0')
  j++;
 
  j--; 
  while(i<j)
  {
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	i++;
	j--;
  }
 	
  printf("string after reverse: %s\n", str);
}
