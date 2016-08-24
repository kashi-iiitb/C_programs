#include <stdio.h>
#ifdef DEBUG
#define KASHI 5
#else
#define KASHI 10
#endif

int main()
{


  char *a[] = {"Hello", "Kashi", "How", "Are", "You"};
  char str[] = "Are";
  char str2[] = "are";
  int flag = 0;
  int i=0;
  printf("Number of elements in a[] is = %d\n", sizeof(a)/sizeof(char*));
  
  for(i=0; i<sizeof(a)/sizeof(char*); i++)
  {
	if(!strcmp(a[i], str2))
		flag = 1;
  }

  if(flag)
	printf("String is present\n");
  else
	printf("String is not present\n");

  char *s = "Hello";
  s++;
  printf("string after s++ is %s\n",s);


  int y=10;
  int x=20;
  y = y++;
  x++,x++;
  printf("y = %d \t x=%d KASHI = \n",y,x);

  char tok[] = "Hello kashi how are you?";
  char *token = strtok(tok," ");
 /* do{
	printf("token=%s\n",token);
  }while((token=strtok(NULL," "))!=NULL);
*/

int *p1= &x;
int *p2= &y;
int z = *p1**p2;
printf("%d %d %d ",x,y,z);
FILE *fp=stdout;
fprintf(fp,"%d",45);
fflush(stdout);
fprintf(stderr," %d",65);
return 0;
}
