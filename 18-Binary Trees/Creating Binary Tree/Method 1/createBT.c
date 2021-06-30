#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

//Allocating new node with given data and NULL left & right pointers
struct node *newNode(int data)
{
    //Allocate memory for new node
    struct node *node = (struct node *) malloc(sizeof(struct node));

    //Assigning data to created node
    node->data = data;

    //Initializing left & right children to NULL
    node->left = NULL;
    node->right = NULL;

    //Returning created node
    return (node);
}

int main()
{
    //Creating root
    struct node *root = newNode(1);

    //Creating left & right children of root (left & right children of 1)
    root->left = newNode(2);
    root->right = newNode(3);

    //Creating a left child of the root's left child (left child of 2)
    root->left->left = newNode(4);

    return 0;
}