/*
This program counts the number of words in a given file.
Program is implemented as a state machine.

	input
state	c	w
0	0	1
1	0	1
*/
#include <stdio.h>
#define IN 0
#define OUT 1

int main(int argc, char*argv[])
{
  FILE *in_file;
  int state=OUT,i=0;
  long wc=0;
  char c;
  char word[100];
  if(argc!=2)
  {
	printf("incorrect number of arguments!!\n");
	exit(1);
  }
  in_file = fopen(argv[1],"r");
  
  while((c=fgetc(in_file))!=EOF)
  {
	switch(state)
	{
		case IN:
			if(c==' ' || c=='\n' || c=='\t')
			{
				word[i]='\0';
				printf("%s\n",word);
				state = OUT;
				wc++;
			}
			else
			{
				word[i++]=c;
			}
			break;
		case OUT:
			if(c==' ' || c=='\n' || c=='\t')
			{
			}
			else
			{
				i=0;
				word[i++]=c;
				state = IN;
			}
			break;
		
	}
  }
  printf("Total words in the file %ld\n", wc);
  fclose(in_file);
  return 0;
}
