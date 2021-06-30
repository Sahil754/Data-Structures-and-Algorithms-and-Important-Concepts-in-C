#include <stdio.h>
#include <stdlib.h>
//#include <string.h> Preprocessor not required

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} NODE;

//Above coded added

void insert(int ins, NODE **start)
{
    if (*start == NULL )
    {
      NODE *newNode = (NODE *)malloc(sizeof(NODE));
      newNode->data = ins;
      newNode->left = NULL;
      newNode->right = NULL;
      *start = newNode;
    }
    if(ins< (*start)->data)
    {
      insert(ins, &(*start)->left);
    }
    else if(ins> (*start)->data)
    {
      insert(ins, &(*start)->right);
    }
}

int getRightMin(NODE *root)
{
    NODE *temp = root;

    //min value should be present in the left most node.
    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

NODE *removeNode(NODE *root, int val)
{
    /*
     * If the node becomes NULL, it will return NULL
     * Two possible ways which can trigger this case
     * 1. If we send the empty tree. i.e root == NULL
     * 2. If the given node is not present in the tree.
     */
    if(root == NULL)
        return NULL;
    /*
     * If root->data < val. val must be present in the right subtree
     * So, call the above remove function with root->right
     */
    if(root->data < val)
        root->right = removeNode(root->right,val);
    /*
     * if root->data > val. val must be present in the left subtree
     * So, call the above function with root->left
     */
    else if(root->data > val)
        root->left = removeNode(root->left,val);
    /*
     * This part will be executed only if the root->data == val
     * The actual removal starts from here
     */
    else
    {
        /*
         * Case 1: Leaf node. Both left and right reference is NULL
         * replace the node with NULL by returning NULL to the calling pointer.
         * free the node
         */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /*
         * Case 2: Node has right child.
         * replace the root node with root->right and free the right node
         */
        else if(root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        /*
         * Case 3: Node has left child.
         * replace the node with root->left and free the left node
         */
        else if(root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        /*
         * Case 4: Node has both left and right children.
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }

    //return the actual root's address
    return root;
}

/*
 First recursively deletes left and right subtree
 then delete root node
*/
void deleteTree(struct node *root){
    if(root == NULL)
        return;
    /* Delete Left sub-tree */
    deleteTree(root->left);
    /* Delete right sub-tree */
    deleteTree(root->right);
     
    /* At last, delete root node */
    printf("Deleteing Node : %d\n", root->data);
    free(root);
     
    return;
}

void printInorder(struct node* node)
{
     if (node == NULL)
          return;
  
     /* first recur on left child */
     printInorder(node->left);
  
     /* then print the data of node */
     printf("%d ", node->data);
  
     /* now recur on right child */
     printInorder(node->right);
    
    printf("\n");
}

int main()
{

    int number;
    NODE *head;
    head=NULL;

    printf("\n");
    
    number = 15;
    insert(number, &head); ///Doesn't need head=insert(...) anymore
    printf("prints the first element (head): %d\n", head->data);

    number = 12;
    insert(number, &head);

    printf("should print the left branch : %d\n", head->left->data);
    
    number = 16;
    insert(number, &head);

    printf("should print the right  branch : %d\n", head->right->data);
    
    printf("\n");
    
    //Code to delete specific node
    head = removeNode(head,12);
    printf("After deletion of 12, the new tree :\n");
    
    printInorder(head);
    //printf("\n");
    
    //Code to delete the entire binary tree
    deleteTree(head);
    
    printf("\n");
}
