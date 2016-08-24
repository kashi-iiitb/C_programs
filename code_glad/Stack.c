#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{

//struct Stack *stack1= (struct Stack *)malloc(sizeof(struct Stack *));
//stack1->top=NULL;
struct Stack *stack1=createStack();
int num=0;
push(&stack1,10);
push(&stack1,20);
push(&stack1,30);
push(&stack1,40);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);


 /*struct node *top=NULL;
 struct node *cur = NULL;
 int num;
 unsigned int choice;
 
 do{
  printf("Enter your choice: 1)push 2)pop 3)display 4)exit: ");
  scanf("%u",&choice);
  switch(choice)
  {
	case 1: printf("Enter the numer to push: ");
		scanf("%d",&num);
		push(&, num);
		break;
  
	case 2: printf("Enter the numer to delete: ");
		scanf("%d",&num);
		//struct node *temp=(struct node *)malloc(sizeof(struct node *));
		delete(&head, num);
		break;
	case 3:
		display(&head);
		break;
	case 4:
		break;
	default:
		printf("Enter proper choice\n"); 
		break;
 }
 }while(choice!=4);
 */
 return 0;
}
