//Delete node as specified location

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototype
void del_pos(struct node **head,int position);

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
    
    //Mention position of node to be deleted
    int position = 2;
    //Call del_pos() function to delete the node to be deleted
    del_pos(&head,position);
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return 0;
}

void del_pos(struct node **head, int position)
{
    struct node *previous = *head;
    struct node *current = *head;
    if (*head == NULL)
    {
        printf("The List is already empty!");
    }
    
    else if (position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    
    else
    {
        while (position !=1) {
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}
