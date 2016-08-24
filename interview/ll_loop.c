#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

int add(struct node **head, int data)
{
  struct node * temp = (struct node * ) malloc (sizeof(struct node));
  temp->data = data;
  temp->next = NULL;

  if(*head == NULL)
	*head = temp;
  else
	{
		temp->next = *head;
		*head = temp;
	}
}

int display(struct node *head)
{
	while(head != NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}

int main()
{
 struct node *head = NULL;
 add(&head,26);
 add(&head,30);
 add(&head,25);
 add(&head,20);
 add(&head,40);
 add(&head,10);

 display(head);

 /*form_loop(&head,20);

 if(loop_exists(&head))
	printf("Loop exists\n");
 else
	printf("Loop doesn't exist\n");*/
 

return 0;
}
