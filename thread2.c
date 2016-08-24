#include <pthread.h>
#include <stdio.h>

int done=0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
 
void* thread_join()
{
  pthread_mutex_lock(&m);
  if(done==0)
	pthread_cond_wait(&c,&m);
  pthread_mutex_unlock(&m);
  
}

void* thread_exit()
{
  pthread_mutex_lock(&m);
  done=1;	
  pthread_cond_signal(&c);
  pthread_mutex_unlock(&m);
} 


void * print_msg(char* msg)
{
	printf("The message passed is %s\n",msg);
	thread_exit();
}

int main()
{
 pthread_t t1,t2;
 char *msg1 = "Thread1";
 
 pthread_create(&t1, NULL, print_msg, (void*)msg1);

 thread_join(t1,NULL);
 printf("parent ends.\n");
 return 0;
}
