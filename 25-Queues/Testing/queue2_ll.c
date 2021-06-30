#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct 
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}


bool enqueue(queue *q, int value)
{
    //Create a new node
    node * newnode = (node*) malloc (sizeof(node));
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = NULL;

    //If there is a tail, connect that tail to this new node.
    if(q->tail != NULL)
    {
        q->tail->next = newnode;
    }
    //Set the tail to be the newnode, it is now the new tail
    q->tail = newnode;
    //Make sure the head makes sense (In case list was empty, 
    //and we just added the first element, then head is still going to be NULL).
    if(q->head == NULL)
    {
        q->head = newnode;
    }
    return true;
}

int dequeue(queue *q)
{
    //check to see if the queue is empty.
    if (q->head == NULL) return QUEUE_EMPTY;

    //save the head of the queue
    node *tmp = q->head;

    //save the result we're going to return
    int result = tmp->value;

    //take it off
    q->head = q->head->next;
    if(q->head == NULL)
    {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main()
{
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 56);
    enqueue(&q2, 78);
    enqueue(&q2, 23);
    enqueue(&q2, 988);
    enqueue(&q3, 13);

    int t;
    while ((t = dequeue(&q2)) != QUEUE_EMPTY)
    {
        printf("t = %d\n", t);
    }
}