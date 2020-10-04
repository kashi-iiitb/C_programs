#include <iostream>
#include <exception>
#include <set>
#include <climits>

struct node{
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node Node;

Node* create_node(int val){
	try{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
	}catch(const std::bad_alloc &e){
		std::cout << "allocation failed\n" <<e.what();
	}
}
Node* insert(Node*head, int val){
	Node* temp=NULL;
	if(head==NULL){
		temp = create_node(val);
		return temp;
	}
	temp = create_node(val);
	Node* prev=NULL;
	Node* cur=head;

	while(cur!=NULL){
		prev = cur;
		if(cur->data<val)
			cur = cur->right;
		else
			cur = cur->left;
	}
	if(prev->data<val){
		prev->right = temp;
		std::cout << "inserted at right\n"; 
	}
	else{
		prev->left = temp;
		std::cout << "inserted at left\n"; 
	}

	return head;
}
void display(Node *head){
	if(head==NULL)
		return;
	display(head->left);
	printf("%d ",head->data);
	display(head->right);
}
/*
Node* delete_node(Node* head){
	Node*temp=head;
	if(temp==NULL){
		std::cout << "can't delete. list is empty\n" ;
		return NULL;
	}
	if(temp->next==NULL){
		std::cout <<"last element deleted.\n";
		delete head;
		return NULL;
	}
	while(temp->next->next!=NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	return head;
}*/

int find_max(Node* root){
	int left,right;
	if(root==NULL)
		return INT_MIN;
	left = find_max(root->left);
	right = find_max(root->right);
	if(left>root->data)
		if(left>right)
			return left;
		else
			return right;
	else 
		if(root->data>right)
			return root->data;
		else
			return right;
}

bool is_bst(Node* head){
	int left_max=0,right_max=0;
  if(head==NULL)
	  return true;
  left_max = find_max(head->left);
  right_max = find_max(head->right);
  std::cout << "\n" << left_max << " "<<right_max << " " << head->data ;
  if(head->left!=NULL && left_max>=head->data )
	  return false;
  if(head->right!=NULL && right_max<head->data)
	  return false;
  if(is_bst(head->left)&&is_bst(head->right))
  	return true;
  else
	  return false;
}

int main(){
  Node *head=NULL;
  head = insert(head,10);
  head = insert(head,20);
  head = insert(head,15);
  head = insert(head,4);
  head = insert(head,8);
  head = insert(head,18);
  head = insert(head,28);
  head = insert(head,12);
  head = insert(head,3);
  head = insert(head,5);
  display(head);
  if(is_bst(head))
	  std::cout << "Yes it is a BST\n" ;
  else
	  std::cout << "No it is not a BST\n";
  /*
  head = delete_node(head);
  display(head);
  head = delete_node(head);
  display(head);
  head = delete_node(head);
  display(head);
  head = delete_node(head);
  display(head);
  head = delete_node(head);
  display(head);*/
}
