#include <stdio.h>
#include <string.h>
#define SIZE 5

/*int swap(char *input[],int i, int j)
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
}*/

int main() {
    int i;
    char *input[] = {"a","orange","apple","mobile","car"};

    int stringLen = sizeof(input) / sizeof(char *);
 //   qsort(input, stringLen, sizeof(char *), myCompare);
    bubsort(input,stringLen);
    for (i=0; i<stringLen; ++i)
        printf("%d: %s\n", i, input[i]);
}
/*int main()
{
 int i=0;
 char *arr[SIZE] = {"Apple", "Kite", "Ship", "Banana", "Elephant"};
 printf("Array of strings before sorting: \n");
 for(i=0;i<SIZE;i++)
  	printf("%s\n",arr[i]);
 qsort(arr,0,SIZE-1); 
 printf("Array of strings after sorting: \n");
 for(i=0;i<SIZE;i++)
  	printf("%s\n",arr[i]);
 return 0;
}*/
