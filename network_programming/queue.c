#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "queue.h"

queueNode* create_queue_node(int val) {
    queueNode *tempQNode = malloc(sizeof(queueNode));
    if(!tempQNode){
        printf("unable to allocate memory\n");
        return NULL;
    }
    tempQNode->tid = val;
    tempQNode->next = NULL;
    return tempQNode;
}

void enqueue(Queue *q, int val) {
    queueNode *tempQNode = create_queue_node(val);

    if(is_queue_empty(q)){
        q->front = q->rear = tempQNode;
        return;
    }
    q->rear->next = tempQNode;
    q->rear = tempQNode;
}

bool is_queue_empty(Queue *q){
    if(q->rear == NULL)
        return true;
    else
        return false;
}

int dequeue(Queue *q) {
    if(is_queue_empty(q)) {
        //printf("queue is Empty, Unable to dequeue");
        return -1;
    }


    queueNode *tempQNodePtr = q->front;
    if(q->front == q->rear){ //there is only one element in the queue
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }    
    tempQNodePtr->next = NULL;
    int tempint = tempQNodePtr->tid;
    free(tempQNodePtr);
    return tempint;
}