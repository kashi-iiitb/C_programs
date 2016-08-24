#include <pthread.h>
#include <stdio.h>

void * odd_fn(char* msg)
{
	printf("The message passed is %s\n",msg);
}

void * even_fn(char* msg)
{
	printf("The message passed is %s\n",msg);
}

int main()
{
 pthread_t t1,t2;
 char *msg1 = "Thread1";
 char *msg2 = "Thread2";
 
 pthread_create(&t1, NULL, odd_fn, (void*)msg1);
 pthread_create(&t2, NULL, even_fn, (void*)msg2);

 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 return 0;
}
