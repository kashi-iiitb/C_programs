#include <stdio.h>
#define TRUE 1
#define FALSE 0

/*int palindrome(char str[])
{
int i = 0;	// i points to the first character in the string
int j = 0;
int flag;

while(str[j] != '\0')
	j++;
j--;		//j points to the last char in the string
 
 flag = TRUE;
 while(i<j)
 {
	if(str[i] != str[j])
	{
		flag = FALSE;
		break;
	}
	i++;
	j--;
 }

 if(!flag)
	return FALSE;
 else
	return TRUE;
}*/
int palindrome(char str[])
{
char *i = str;	// i points to the first character in the string
char *j = str;
int flag;

while(*j != '\0')
	j++;
j--;		//j points to the last char in the string
 
 flag = TRUE;
 while(i<j)
 {
	if(*i != *j)
	{
		flag = FALSE;
		break;
	}
	i++;
	j--;
 }

 if(!flag)
	return FALSE;
 else
	return TRUE;
}

int remove_char(char str[], char c)
{

 
 char *temp=str;
 //printf("String passed is %s and char is %c\n",str,c);
 //printf("Hello World!!\n");
 while((*temp != c) && (*temp != '\0'))
	temp++;
 if(*temp == c)
	do{
		*temp = *(temp+1);
		temp++;
	}while(*temp !='\0');

}

int main()
{
 char str[20] = "kashihsak";
/* if(palindrome(str))
	printf("%s is palindrome.\n",str);
 else
	printf("%s is not palindrome.\n",str);
*/ remove_char(str,'i');
 printf("String after removing char is %s",str);
 return 0;
}
