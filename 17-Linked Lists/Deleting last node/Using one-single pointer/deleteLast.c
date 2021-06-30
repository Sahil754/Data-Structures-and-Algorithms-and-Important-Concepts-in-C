//Deleting last node of list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Prototypes
void del_last(struct node *head);

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
    
    del_last(head);
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    
    return 0;
}

void del_last(struct node *head)
{
    //If the List is empty
    if (head == NULL)
    {
        printf("List is already empty!");
    }
    
    //If there's only 1 node
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    
    //If there are more than 1 node in the list
    else
    {
        struct node *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}
