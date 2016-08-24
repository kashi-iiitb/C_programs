#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int x=0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void * till5(void* id)
{
	while(x<10)
	{
	pthread_mutex_lock(&m);
	if(x<5)
	{	x++;
		printf("till5 fn: %d\n",x);
	}
	if(x==5)
		pthread_cond_signal(&c);
	pthread_mutex_unlock(&m);
//	pthread_exit(NULL);
	sleep(1);
	}
}

void * from5(void* id)
{
	while(x<10)
	{
		pthread_mutex_lock(&m);
		//	x++;
			printf("from5 fn: %d\n",x);
		//	sleep(1);
		while(x<5)
			pthread_cond_wait(&c,&m);
		x++;
		pthread_mutex_unlock(&m);
	//	pthread_exit(NULL);
		}
}

int main()
{
	pthread_t t1,t2;
	long tid1=1, tid2=2;
	pthread_create(&t1,NULL,till5,(void*)tid1);
	pthread_create(&t2,NULL,from5,(void*)tid2);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}

