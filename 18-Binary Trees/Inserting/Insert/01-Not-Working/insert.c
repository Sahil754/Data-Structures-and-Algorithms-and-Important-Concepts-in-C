//Code not working

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} NODE;

void *insert(int ins, NODE *start)
{
    NODE *newNode = malloc(sizeof(NODE));
    if (start == NULL )
    {
        newNode->data = ins;
        newNode->left = NULL;
        newNode->right = NULL;

    }
    if(ins<start->data)
    {
        insert(ins, start->left);
    }
    else if(ins>start->data)
    {
        insert(ins, start->right);
    }
}

int main()
{
    int number;
    NODE *head;
    head=NULL;

    number = 15;
    head = insert(number, head);
    printf("prints the first element (head): %d", head->data);

    number = 12;
    insert(number, head);

    printf("should print the left branch : %d", head->left->data);  // <- THIS DOES NOT SHOW UP

}
