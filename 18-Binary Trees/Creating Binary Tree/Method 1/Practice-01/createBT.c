#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/*Creating new node & assigning values to it's fields*/
struct node *newNode(int data)
{
    //Allocate memory
    struct node *node = (struct node *) malloc(sizeof(struct node));
    
    if(node != NULL)
    {
    //Assigning data to data field
    node->data = data;
    
    //Assign values to right & left children
    node->left = NULL;
    node->right = NULL;
    }
    //Returning new node
    return (node);
}

int main()
{
    //Creating root
    struct node *root = newNode(1);
    
    //Creating new nodes and assigning them values
    root->left = newNode(2);
    root->right = newNode(3);
    
    //Creating a new left child node of of the left child of the root
    root->left->left = newNode(4);
    
    /* //How it would look like visually
      1
     / \
    2   3
   /
  4
   */
    
    //Freeing the binary tree
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}
