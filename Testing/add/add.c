#include <stdio.h>

int add(int a, int b)
{
	return (long)(a+b);
}
int main(int argc, char* argv[])
{
  printf("%d",add(atoi(argv[1]),atoi(argv[2])));
  return 0;
}
