#include <stdio.h>
#include <stdlib.h>

//Creating node structure
struct node
{
    int data;
    struct node *left;
    struct ndoe *right;
}

//creating function that returns new node

struct node *newNode(int data)
{
    //Allocate memory and create pointer
    struct node *node = (struct node *)malloc(sizeof(struct node));
    
    //Assigning data
    node->data = data;
    
    //Assigning NULL to left & right child
    node->left = NULL;
    node->right = NULL;
    
    return (node);
}

//Post Oder Traversal Function
void printPostorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    
    //first recursive on left subtree
    printPostorder(node->left);
    
    //recursive on right subtree
    printPostorder(node->right);
    
    //printing root node
    printf("%d", node->data);
}

//In-Order Traversal Function
void printInorder(struct node *node)
{
    if(node == NULL)
    {
        return;
    }
    
    //first recursive on left child
    printInorder(node->left);
    
    //Print root node
    printf("%d", node->data);
    
    //Recursive on right child
    printInorder(node->right);
}

//Pre-Order Traversal Function

