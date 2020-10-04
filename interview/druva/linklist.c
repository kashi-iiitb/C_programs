#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};
typedef struct node Node;

Node* create_node(int val){
	Node* temp = (Node*)malloc(sizeof(Node));
	if(temp==NULL){
		perror("malloc failure");
		exit(1);
	}
	temp->data = val;
	temp->next = NULL;
	return temp;
}
Node* insert(Node*head, int val){
	Node* temp=NULL;
	if(head==NULL){
		temp = create_node(val);
		return temp;
	}
	temp = create_node(val);
	Node* p=head;
	while(p->next!=NULL)
		p = p->next;
	p->next = temp;
	return head;
}
void display(Node *head){
	Node*p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
Node* delete(Node* head){
	Node*temp=head;
	if(temp==NULL){
		printf("can't delete. list is empty\n");
		return NULL;
	}
	if(temp->next==NULL){
		printf("last element deleted.\n");
		free(head);
		return NULL;
	}
	while(temp->next->next!=NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	return head;
}

int main(){
  Node *head=NULL;
  head = insert(head,10);
  head = insert(head,20);
  head = insert(head,30);
  head = insert(head,40);
  head = insert(head,50);
  display(head);
  head = delete(head);
  display(head);
  head = delete(head);
  display(head);
  head = delete(head);
  display(head);
  head = delete(head);
  display(head);
  head = delete(head);
  display(head);
}
