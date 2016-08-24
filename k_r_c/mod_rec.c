#include <stdio.h>

int mod(int x, int y)
{
  if(x<y)
	return x;
  else
	mod(x-y,y);
}

int main()
{
  int x=13;
  int y=4;
  int rem=0;
  rem = mod(x,y);
  printf("x%%y is %d\n",rem);
return 0;
}
