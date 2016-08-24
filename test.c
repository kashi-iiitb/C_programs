#include <stdio.h>

int main()
{
char s[] = "Hello";
int i=0;

do{
  putchar(s[i++]);
  putchar('\n');
}while(s[i]!='\0');
}
