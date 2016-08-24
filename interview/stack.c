#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

int push(struct node **top, int data)
{
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(*top == NULL)
	{
		*top = temp;
		return;
	}
	else
	{
		temp->next = *top;
		*top = temp;
	}
}

int pop(struct node

int main()
{
 struct node *top = NULL;
 push(&top,10);
 push(&top,20);
 push(&top,30);
 push(&top,40);
 push(&top,50);
 printf("%d\n",pop(&top));
 printf("%d\n",pop(&top));
 printf("%d\n",pop(&top));
 printf("%d\n",pop(&top));
 printf("%d\n",pop(&top));
 printf("%d\n",pop(&top));
 return 0;
}

