#include <iostream>
#include <exception>
#include <set>

struct node{
  int data;
  struct node* next;
};
typedef struct node Node;

Node* create_node(int val){
	try{
	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL;
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
	Node* p=head;
	while(p->next!=NULL)
		p = p->next;
	p->next = temp;
	return head;
}
void display(Node *head){
	Node*p=head;
	while(p!=NULL){
//		printf("%d ",p->data);
		std::cout << p->data << " ";
		p = p->next;
	}
//	printf("\n");
	std::cout << "\n";
}
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
}

bool detect_loop (Node* head){
  std::set<Node*> addr;
  Node *p = head;
  bool res=false;
  while(p!=NULL){
	  if(addr.insert(p).second==false){
		  std::cout << "there is a loop at " << p << "\n";
		  res=true;
		  break;
	  }
	  std::cout << p << "\n";
	  p = p->next;
  }
  return res;
  
}

int main(){
  Node *head=NULL;
  head = insert(head,10);
  head = insert(head,20);
  head = insert(head,30);
  head = insert(head,40);
  head = insert(head,50);
  display(head);
  head->next->next->next->next = head;
  if(detect_loop(head)){
	  std::cout << "there is a loop in the linked list\n";
  }else{
	  std::cout << "No there is no loop in the linked list\n";
  }
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
