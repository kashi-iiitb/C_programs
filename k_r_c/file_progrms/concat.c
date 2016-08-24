#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp1, *fp2;
	char *input_line;
	char *output_line;
	char word[100] = "Kashi";
	char new_word[100] = "Bangalore";
	int i,j;
	size_t n=0;
	unsigned char ch;
	
	fp1 = fopen("test.txt","a");
	if(fp1==NULL)
	{
		perror("Error:");
		exit(-1);
	}
	fp2 = fopen("out.txt","r");
	if(fp2==NULL)
	{
		perror("Error:");
		exit(-1);
	}
	i=0;
	ch = fgetc(fp2);
	while(!feof(fp2))
	{
		printf("wrote %c\n",ch);
		fputc(ch,fp1);
		ch = fgetc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
