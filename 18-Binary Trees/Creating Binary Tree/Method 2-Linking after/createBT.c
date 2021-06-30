#include <stdio.h>
#include <stdlib.h>

typedef struct treenode 
{
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createnode(int value)
{   
    //Allocating memory for new node
    treenode *result = malloc(sizeof(treenode));
    if(result != NULL)
    {
        //Assigning vale of the newly created node
        result->value = value;

        //Initializing left & right children of new node to NULL
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

int main()
{
    //Creating new nodes for the Binary Tree
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);

    /*Creating the binary tree using previously created nodes
    n1 is assumed now to be the root of the tree node*/
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

        /* n1(10)
          /  \
      n2(11)  n3(12)
              / \
        n4(13)   n5(14)
        */
    
    //Freeing all the nodes (allocated memory)
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}
