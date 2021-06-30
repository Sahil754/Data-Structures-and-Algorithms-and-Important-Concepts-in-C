
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right, *left;
} Node;

void insert (int ins, Node **start)
{
    if (*start == NULL)
    {
        //Create new node & assigning it to head
        Node *node = (Node *) malloc(sizeof(Node));
        node->data = ins;
        node->left = NULL;
        node->right = NULL;
        *start = node;
    }
    //Insert operations
    if (ins < (*start)->data)
    {
        insert(ins, &(*start)->left);
    }
    
    else if (ins > (*start)->data)
    {
        insert(ins, &(*start)->right);
    }
}

int main()
{
    int number;
    Node *head = NULL;
    
    number = 15;
    insert(number, &head);
    printf("The root value of the Binary tree is: %d\n", head->data);
    
    number = 12;
    insert(number, &head);
    printf("The left child of the root's value is: %d\n", head->left->data);
}
