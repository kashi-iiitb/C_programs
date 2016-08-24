#include <stdio.h>

int main()
{
  char str[100] =""; 
  scanf("%[^\n]s",str);
  printf("read line is %s",str);

}
