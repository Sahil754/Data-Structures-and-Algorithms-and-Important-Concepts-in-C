#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

//Protypes
void add_at_end(struct node *head, int data);
void print_data(struct node *head);

int main()
{
    //Create first node, allocating memory for it, creating head pointer
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    //Creating second node
    struct node *second = (struct node *) malloc(sizeof(struct node));
    second->data = 98;
    second->link = NULL;

    //Linking first and second nodes
    head->link = second;

    //Creating third node
    struct node *third = (struct node *) malloc(sizeof(struct node));
    third->data = 3;
    third->link = NULL;

    //Linking second and third nodes
    head->link->link = third;

    /*Adding a new node to the list at the end*/
    add_at_end(head, 67);

    /*Traversing through the Linked List and printing out the data to the screen of each of the nodes, 
    including the new node*/
    print_data(head);

    return 0;
}

void add_at_end(struct node *head, int data)
{
    //Created ptr and temp pointers
    struct node *ptr , *temp;
    
    /*Getting pointer named ptr to point to the first node also 
    (as head pointer already pointes to the first node of the Linked List)*/
    ptr = head;
    
    //Creating a new node and assigning its address to the pointer named temp/temp pointer
    temp = (struct node *) malloc(sizeof(struct node));

    //Adding data anda link info to the newly created node
    temp->data = data;
    temp->link = NULL;

    //Traversing to the last node of the Linked List, and exiting outside the loop once the last node is reached
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    //Linking the current last node to the newly created last node
    ptr->link = temp;
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