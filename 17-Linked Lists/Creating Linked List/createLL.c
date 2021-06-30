/*Creating a Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

int main()
{
    /* -Creating a head pointer, and assigning it the address of the new node returned by the head pointer 
       -Allocating memory/creating the new first node
       -Don't need to type cast to struct node pointer, as automatically done, but is good practice to do so*/
    struct node *head = (struct node *) malloc(sizeof(struct node));

    //Assigning the first node values, for the data and link parts of the first node
    head->data = 45;
    head->link = NULL;

    //Creating a second node and assigning values to it's data and link parts:
    struct node *current = (struct node *) malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;

    //Linking the first and second nodes together
    head->link = current;

    //Creating the third node of the linked list and assigning data to it using the existing current pointer:
    current = (struct node *) malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    //Linking the second and third nodes of the linked list together
    head->link->link = current;

    //Retruning 0 for the main, to signify that the program ran successfully (Is an exit code)
    return 0;
}