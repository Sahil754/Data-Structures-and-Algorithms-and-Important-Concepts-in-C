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
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    
    return 0;
}

void del_last(struct node *head)
{
    //Check if it's empty
    if (head == NULL)
    {
        printf("List is already empty!");
    }
    //Check if there's only one node in the list
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    //If there's more than one node
    else
    {
        struct node *tmp = head;
        struct node *tmp2 = head;
        while (tmp->link != NULL)
        {
            tmp2 = tmp;
            tmp = tmp->link;
        }
        tmp2->link = NULL;
        free(tmp);
        tmp = NULL;
    }
}
