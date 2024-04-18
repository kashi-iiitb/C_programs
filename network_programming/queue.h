#include <stdbool.h>
typedef struct queueNode{
    int tid;
    struct queueNode *next;
}queueNode;

typedef struct queue{
    struct queueNode *front;
    struct queueNode *rear;
}Queue;

queueNode* create_queue_node(int val);
void enqueue(Queue *q, int val);
bool is_queue_empty(Queue *q);
int dequeue(Queue *q);

