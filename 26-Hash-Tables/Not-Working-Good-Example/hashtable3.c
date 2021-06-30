#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char * name;
    struct node *next;
} node;

node *first = NULL;

//Inserts a name called buffer into our linked list
void insert(char *buffer)
{
    // try to instantiate node for number
    node *newptr = malloc(sizeof(node));
    if (newptr == NULL)
    {
        return;
    }

    // make a new pointer
    newptr->name = buffer;
    newptr->next = NULL;

    // Check for empty list
    if ( first == NULL)
    {
        first = newptr;
    }

    // Check for insertion at tail
    else
    {
        // Keep track of the previous spot in list
        node *predptr = first;

        // Because we don't know how long this list is
        // we must induce a forever loop until we find the end
        while(true)
        {
            // check if it is the end of the list
            if (predptr -> next == NULL)
            {
                // Add new node to end of list
                predptr->next = newptr;

                // Break out of forever loop
                break;
            }

            // update pointer
            predptr = predptr->next;
        }
    }
}