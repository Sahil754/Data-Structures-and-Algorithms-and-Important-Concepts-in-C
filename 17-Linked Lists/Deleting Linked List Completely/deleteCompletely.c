//Delete Linked List Completely

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototype
struct node *del_list(struct node *head);

int main()
{
    //Creating first node
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    //Creating second node
    struct node *second = (struct node *) malloc(sizeof(struct node));
    second->data = 98;
    second->link = NULL;
    
    //Linking first & second node
    head->link = second;
    
    //Creating third node
    second = (struct node *) malloc(sizeof(struct node));
    second->data = 3;
    second->link = NULL;
    
    //Linking second and third nodes
    head->link->link = second;
    
    head = del_list(head);
    if (head == NULL)
    {
        printf("Linked List Deleted Successfully!\n");
    }
    
    return 0;
}

struct node *del_list(struct node *head)
{
    struct node *ptr = head;
    
    while (head != NULL)
    {
        ptr = ptr->link;
        free(head);
        head = ptr;
    }
    return head;
}
