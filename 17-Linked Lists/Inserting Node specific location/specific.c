//Inserting node at specific location

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototypes
void add_specific(struct node *head, int data, int position);

int main()
{
    //Creating first/head node
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    //Creating second node
    struct node *second = (struct node *) malloc(sizeof(struct node));
    second->data = 98;
    second->link = NULL;
    
    //Linking head and second node
    head->link = second;
    
    //Creating third node
    second = (struct node*) malloc(sizeof(struct node));
    second->data = 3;
    second->link = NULL;
    
    //Linking second and third nodes
    head->link->link = second;
    
    add_specific(head, 67, 3);
    
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    
    
    return 0;
}

void add_specific(struct node *head, int d, int position)
{
    //Creating new node to be added to a specific location in the Linked List
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = d;
    new->link = NULL;
    
    //Traversal
    struct node *temp = head;
    position--;
    while(position !=1)
    {
        temp = temp->link;
        position--;
    }
    new->link = temp->link;
    temp->link = new;
}
