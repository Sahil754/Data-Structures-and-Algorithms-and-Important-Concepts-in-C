//Deleting first node of list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototypes
struct node *del_first(struct node *head);

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
    
    struct node *ptr;
    head = del_first(head);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return 0;
}


struct node *del_first(struct node *head)
{
    if (head == NULL) {
        printf("List is already empty!");
    }
    else
    {
        //Creating temp pointer that will store the address of the current head
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}

