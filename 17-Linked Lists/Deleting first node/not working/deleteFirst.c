//Deleting first node of list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

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
    
    //Creating temp pointer that will store the address of the current head
    struct node *temp = head;
    //printf("%d ", second->data);
    
    return 0;
}
