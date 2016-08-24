#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
void push(struct Stack **stack1, int num)
{
	struct StackNode *temp=(struct StackNode *)malloc(sizeof(struct StackNode *));
	temp->data = num;
	temp->next = (*stack1)->top;
	(*stack1)->top = temp;
}

void pop(struct Stack **stack1, int *pop_elem)
{
		if((*stack1)->top==NULL)
		{
			printf("Cant Pop, the Stack is empty\n");
			return ;
		}
		struct StackNode *temp = (*stack1)->top;
		//struct node *prev = NULL;
		(*stack1)->top = ((*stack1)->top)->next;
		*pop_elem = temp->data;
		free(temp);
}

/*void display(struct node**head)
{
	struct node *cur = *head; 
	while(cur!=NULL)
	{
		printf(" %d",cur->data);
		cur=cur->next;
	}
	printf("\n");
}*/

struct Stack* createStack()
{
	struct Stack *temp= (struct Stack *)malloc(sizeof(struct Stack *));
	temp->top=NULL;
	return temp;	
}


