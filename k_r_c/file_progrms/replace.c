#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp1, *fp2;
	char input_line[1024];
	char output_line[1024];
	char word[100] = "Kashi";
	char new_word[100] = "Bangalore";
	int i,j;
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
	
	while(getline(&input_line,1024,fp1)
	{
		i=0;
		j=0;
		while(i<strlen(input_line))
		{
			if((index = strstr(input_line,word))!=NULL)
			{
				for(;i<index;i++,j++)
				{
					output_line[j++]=input_line[i];
				}
				
			}
			else
			{
				for(;i<strlen(input_line);i++,j++)
				{
					output_line[j++]=input_line[i];
				}
				
			}
		}
		if(strcmp(word,new_word)==0)
		{
			fprintf(fp2,"%s",new_word);
		}
		else
		{
			fprintf(fp2,"%s",word);
		}
	}
	return 0;
}
