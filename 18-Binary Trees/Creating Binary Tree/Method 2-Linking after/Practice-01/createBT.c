#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

//creates new node
treenode *createnode(int value)
{
    //Allocating memory for new node
    treenode *node = malloc(sizeof(treenode));
    
    //Making sure node is not equal to NULL,in which case code is not evaluated
    if(node != NULL)
    {
        //Assigning value to new node
        node->value = value;
        
        //Assigning NULL to new node's right and left children
        node->left = NULL;
        node->right = NULL;
    }
    
    return node;
}

int main()
{
    //Creating new nodes for binary tree
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);
    
    //Linking the nodes together to create a binary tree
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    
    //Freeing all the allocated memory through the nodes
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    
    return 0;
}
