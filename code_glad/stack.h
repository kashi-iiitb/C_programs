struct StackNode{
 int data;
 struct StackNode *next;
};

struct Stack{
 struct StackNode *top;
};
void push(struct Stack **stack1, int num);
void pop(struct Stack **stack1, int *pop_elem);
struct Stack* createStack();
