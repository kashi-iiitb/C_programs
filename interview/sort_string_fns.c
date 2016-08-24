#include "sort_string.h"
#include "sort_string.h"

int swap(char *input[],int i, int j)
{
	char *temp = input[i];
	input[i] = input[j];
	input[j] = temp;
}

int bubsort(char *input[],int len)
{
	int i;
	int j;
	for(i=0; i<len-1; i++)
		for(j=0;j<len-i-1;j++)
			if(strcmp(input[j],input[j+1])>0)
				swap(input,j,j+1);
}

