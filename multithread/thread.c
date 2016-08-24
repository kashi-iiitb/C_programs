#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <pthread.h>
void do_one_thing()
{
  int i, j, x;
  for (i = 0;  i < 4; i++) {
    printf("doing one thing\n");
    for (j = 0; j < 10000; j++) x = x + i;
  }
}
void do_another_thing()
{
  int i, j, x;
  for (i = 0;  i < 4; i++) {
    printf("doing another \n");
    for (j = 0; j < 10000; j++) x = x + i;
  }
}

int main(void)
{
  pthread_t pthd1, pthd2;
  int r1,r2;
  r1 = pthread_create(&pthd1,NULL,do_one_thing,NULL) ; 
  r2 = pthread_create(&pthd2,NULL,do_another_thing,NULL);  
  
  /* parent */
  pthread_join(pthd1, NULL);
  pthread_join(pthd2, NULL);
//  do_wrap_up(*r1p, *r2p);
  return 0;
}

