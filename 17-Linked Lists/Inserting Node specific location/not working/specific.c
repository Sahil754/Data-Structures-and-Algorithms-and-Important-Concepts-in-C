//Inserting node at specific location

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototypes
void add_specific(struct node **head, int data, int position);
void print_data(struct node *head);

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
    
    add_specific(&head, 67, 3);
    
    print_data(head);
    
    return 0;
}

void add_specific(struct node **head, int d, int position)
{
    //Creating new node to be added to a specific location in the Linked List
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = d;
    new->link = NULL;
    
    //Traversal
    int i = 0;
    struct node *temp;
    temp = *head;
    while(i < position)
    {
        //printf("%d ", temp->data);
        temp = temp->link;
        i++;
    }
    new->link = temp->link;
    temp->link = new;
}

//Writing a function that will help print out the data in the Linked List
void print_data(struct node *head)
{
    //Checking if the head has the address of NULL, if so means that the list is empty
    if(head == NULL)
    {
        //Print out: Linked List is empty
        printf("Linked List is empty");
    }
    //Creating a new pointer and assigning the value of NULL to it
    struct node *ptr = NULL;

    //Assigning the addres of head to the new pointer ptr
    ptr = head;

    /*Using ptr pointer to traverse the linked list and print it's data (data values of the pointer ptr)*/
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
