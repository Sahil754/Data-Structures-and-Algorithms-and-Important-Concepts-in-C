#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node 
{
    int value;
    struct node *next;
} node;

//Empty Linked List - Global head pointer
node *head = NULL;


bool push(int value)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false; //Checks if we're out of memory and sees if malloc failed to allocate a new node

    newnode->value = value;
    newnode->next = head;
    head = newnode;
    return true;
}

int pop() 
{
    if (head == NULL) return STACK_EMPTY;

    int result = head->value;
    node *tmp = head;
    head = head->next;
    free(tmp);
    return result;
}

int main()
{
    push(56);
    push(78);
    push(13);

    int t;
    while ((t = pop()) != STACK_EMPTY)
    {
        printf("t = %d\n", t);
    }
}