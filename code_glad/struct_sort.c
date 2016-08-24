#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define QUEUE_SIZE 6

typedef struct
{
  int height;
  int in_front;
}standing;

typedef struct
{
  int data[STACK_SIZE];
  int top;
}Stack;

int compare(const void *a, const void *b)
{
  standing *tempA = (standing *)a;
  standing *tempB = (standing *)b;
  return (tempB->height - tempA->height);
}

int init(Stack *st)
{
  st->top = -1;
}

int push(Stack *st, int data)
{
  if(st->top == STACK_SIZE-1)
	printf("Stack full\n");
  else
  {
	st->data[++st->top] = data;
 	printf("Pushed\n");
  }
}

int pop(Stack *st)
{
  if(st->top == -1)
	printf("Stack empty\n");
  else
  {
 	printf("Popeddd\n");
	return st->data[st->top--];
  }
}


int main()
{
  int i=0;
  standing queue[6] = {{5,0},{3,1},{2,2},{6,0},{1,3},{4,2}};

  printf("Before qsort:\n");
  for(i=0; i<QUEUE_SIZE; i++)
    printf("height=%d \t in_front=%d\n",queue[i].height,queue[i].in_front);
  
  qsort(queue,QUEUE_SIZE,sizeof(standing),compare);

  printf("After qsort:\n");
  for(i=0; i<QUEUE_SIZE; i++)
    printf("height=%d \t in_front=%d\n",queue[i].height,queue[i].in_front);

  Stack ms,ts;
  init(&ms);
  init(&ts);
  int temp_ht=0;
  for(i=0; i<QUEUE_SIZE; i++)
  {
	int j=0;
	for(j=0;j<queue[i].in_front; j++)
	{
		temp_ht = pop(&ms);
		push(&ts, temp_ht);
	}
	push(&ms,queue[i].height);
	for(j=0;j<queue[i].in_front; j++)
	{
		temp_ht = pop(&ts);
		push(&ms, temp_ht);
	}
  }
  
  printf("The standing sequence is as follows:\n");
  for(i=0; i<QUEUE_SIZE; i++)
  {
	printf("%d\n",pop(&ms));
  }

/*  push(&ms,10);
  push(&ms,20);
  push(&ms,30);
  push(&ms,40);
  pop(&ms);
  pop(&ms);
  pop(&ms);*/
}
