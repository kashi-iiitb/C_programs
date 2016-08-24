/*
	This program finds the largest line in command line input and prints it as output.
*/
#include <stdio.h>
#define MAXLEN 100

int get_line(char line[],const int max)
{
 int i=0;
 char c;
 while((c=getchar())!='\n' && i<max)
 {
	line[i++] = c;
 }
 line[i] = '\0';
 printf("get_line called: %s\n",line);
 return i;
}

int copyline(char src[], char dest[])
{
  int i=0;
  while(src[i] != '\0')
  {
	dest[i] = src[i++]; 
  }
  dest[i] = '\0';
 printf("copy_line called: %s %s\n",src, dest);

}

int main()
{

  int len=0,max_len=0;
  char line[MAXLEN],longest_line[MAXLEN];
  while((len=get_line(line,MAXLEN))>0)
  {
  //  	printf("get_line called: %s\n",line);

	if(len > max_len)
	{
		max_len = len;
		copyline(line,longest_line);
	}	
  }
	printf("%s\n",longest_line);
return 0;
}
