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
	
	fp1 = fopen("test.txt","r");
	if(fp1==NULL)
	{
		perror("Error:");
		exit(-1);
	}
	fp2 = fopen("out.txt","w+");
	if(fp2==NULL)
	{
		perror("Error:");
		exit(-1);
	}
	i=0;
	while((n=getline(&input_line,&n,fp1))!=-1)
	{
		if(i!=3)
			fprintf(fp2,"%s",input_line);
		i++;	
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
