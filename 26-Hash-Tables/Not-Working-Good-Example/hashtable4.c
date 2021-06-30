#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char * name;
    struct node *next;
} node;

node *first[26] = {NULL};

int main(char *name)
{
    // Hash the name into a spot
    int hashedValue = hash(name);

    // Insert the name in table with hashed value
    insert(hashedValue, name);
}

// Takes a string and hashes it into the correct bucket
int hash(const char *buffer)
{
    // Assign a number to the first cahr of buffer from 0-25
    return tolower(buffer[0]) - 'a';
}

// takes a string and inserts it into a linked list at a part of the hash table
void insert(int key, const char *buffer)
{
    // try to instantiate node to insert word
    node *newptr = malloc(sizeof(node));
    if (newptr == NULL)
    {
        return;
    }

    // make a new pointer
    strcpy(newptr->name, buffer);
    newptr->next = NULL;

    // Check for empty list
    if ( first[key] == NULL)
    {
        first[key] = newptr;
    }

    // Check for insertion at tail
    else
    {
        // Keep track of the previous spot in list
        node *predptr = first[key];

        // Because we don't know how long this list is
        // we must induce a forever loop until we find the end
        while(true)
        {
            // check if it is the end of the list
            // insert at tail
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