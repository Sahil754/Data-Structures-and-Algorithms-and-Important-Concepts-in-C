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

typedef node *stack;

//Passing a stack into the function,
//so the function knows what stack we want to push to or pop from
//Passing a pointer to the stack, that allows us to change the head
//, something which will affect thigns outside the function also
bool push(stack *mystack, int value)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;

    newnode->value = value;
    newnode->next = *mystack;
    *mystack = newnode;
    return true;
}

int pop(stack *mystack) 
{
    if (*mystack == NULL) return STACK_EMPTY;

    int result = (*mystack)->value;
    node *tmp = *mystack;
    *mystack = (*mystack)->next;
    free(tmp);
    return result;
}

int main()
{
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    push(&s1, 56);
    push(&s2, 78);
    push(&s2, 23);
    push(&s2, 988);
    push(&s3, 13);

    int t;
    while ((t = pop(&s2)) != STACK_EMPTY)
    {
        printf("t = %d\n", t);
    }
}