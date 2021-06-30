/*Adding a node to the beginning of the Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototypes
void add_beg2(struct node **head, int data);

int main()
{
    //Creating first node (head)
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    //Creating second node
    struct node *second = (struct node *) malloc(sizeof(struct node));
    second->data = 98;
    second->link = NULL;
    
    //Linking head and second node
    head->link = second;
    
    //Creating data for new node
    int data = 3;
    
    /*Adding a node to the beginning of the linked list using add_beg2 function*/
    add_beg2(&head, data);
    
    /*Looping through new Linked list & printing its data*/
    second = head;
    while(second != NULL)
    {
        printf("%d ", second->data);
        second = second->link;
    }
    printf("\n");
    /*Exit code for if the function was successful*/
    return 0;
}

/*Implementing function that adds node at the beginning of the Linked List*/
void add_beg2(struct node **head, int d)
{
    //Creating new node to be added at the beginning of the Linked List
    struct node *new = (struct node *) malloc(sizeof(struct node));
    
    //Assigning data to the new node
    new->data = d;
    new->link = NULL;
    
    //Linking new head and old node that was the former head. In short: Making the new node to be the head
    new->link = *head;
    
    //Making head point to the new node
    *head = new;
}
