#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

/*
//Search Code not working, gives an error that all paths are not returning a value or such, since it's a non void function
node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        return search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        return search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}
*/

// C function to search a given val (value) in a given BST - Using Double Pointers
node *search(node **root, int val)
{
    //Base Cases: root is null or val (key) is present at root
    if(*root == NULL || (*root)->data == val)
    {
        return *root;
    }

    //If searched node is greater than root value
    else if (val > (*root)->data)
    {
       return search(&((*root)->right), val);
    }

    else
    {
        return search(&((*root)->left), val);
    }
}


int main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    // Search node into tree - Using double pointers
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched Node found in tree = %d\n", tmp->data);
    }

    else
    {
        printf("Searched node not found in tree.\n");
    }

    /* Deleting found in tree all nodes of tree , tmp->data*/
    deltree(root);
    return 0;
}