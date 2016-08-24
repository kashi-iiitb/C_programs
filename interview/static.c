#include <stdio.h>

#define N 5

int foo(int n)
{
  int x=N;
  if(n==0)
	return;
  x--;
  foo(n-1);
  printf("%d\n",x);
}

int main()
{
  int *p = NULL;
  p++;
  printf("%d\n",p);
//  foo(5);
}
