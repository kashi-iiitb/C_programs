#include <stdio.h>

int main()
{
  unsigned int num = 89;
  unsigned int rev_num = 0;
  int i=0;
  int word_len = sizeof(int)*4;
  for(i=0; i<word_len; i++)
  {
	if(num & (1<<i))
	rev_num = rev_num | (1 << (word_len-1-i));
  }
  printf("sizeof int is %d\n",sizeof(int));
  printf("The number %u after reversal is %u\n",num, rev_num);

return 0;
}
