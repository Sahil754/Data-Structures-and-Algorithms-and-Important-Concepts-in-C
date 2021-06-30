#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    //or line 7&8 can be written together as "struct node *left, *right;" on one line
} Node;

void insert(int ins, Node **start)
{
    if(*start == NULL)
    {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = ins;
        newNode->left = NULL;
        newNode->right = NULL;
        *start = newNode;
    }
    
    if (ins < (*start)->data)
    {
        insert(ins, &(*start)->left);
    }
    
    else if(ins > (*start)->data)
    {
        insert(ins, &(*start)->right);
    }
}

/*
Node* getNewNode(int data) {
  // dynamically allocate memory for a new node
  Node* newNode = (struct node*)malloc(sizeof(struct node));
  
  //populate data in new Node 
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
   
  return newNode;
}

Node* generateBTree(){
    // Root Node
    Node* root =  getNewNode(1);
  
    root->left = getNewNode(2);
    root->right = getNewNode(3);
  
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);
  
    root->left->left->left = getNewNode(8);
     
    return root;
}
*/

int getRightMin(Node *root)
{
    Node *temp = root;
    
    //Min value should be present in the left most node
    //Traverses to the most left node
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    
    //Returns the value of the most left node
    return temp->data;
}

Node *removeNode(Node *root, int val)
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
            Node *temp = root->right;
            free(root);
            return temp;
        }
        /*
         * Case 3: Node has left child.
         * replace the node with root->left and free the left node
         */
        else if(root->right == NULL)
        {
            Node *temp = root->left;
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

void deleteTree(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    // Delete left sub-tree
    deleteTree(root->left);

    // Delete right sub-tree
    deleteTree(root->right);

    //Prints out data of the node that has just been deleted
    printf("Deleting Node: %d\n", root->data);
    
    //Deleting root node
    free(root);

    return;
}

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    //First recursion on the left child
    printInorder(node->left);

    //Prints the data of the root node
    printf("%d ", node->data);

    //Recursion on the right child
    printInorder(node->right);

    printf("\n");
}

int main()
{
    int number;
    //Node *head = generateBTree();
    Node *head;
    head = NULL;
    
    printf("\n");

    number = 15;
    insert(number, &head);
    printf("Prints the first element (head): %d\n", head->data);
    
    
    number = 12;
    insert(number, &head);
    printf("Prints the left branch: %d\n", head->left->data);
    
    number = 16;
    insert(number, &head);
    printf("Prints the right branch: %d\n", head->right->data);
    
    /*
    //Above code creates the following binary tree:
                15
               /  \
              12  16
    */

    printf("\n");

    //Deleting specific node
    head = removeNode(head, 16);

    printf("After deletion of 16, new tree: \n");
    printInorder(head);
    printf("\n");

    //Code to delete whole binary tree:
    printf("Deleting Entire Binary Tree:\n");
    deleteTree(head);

    printf("\nAfter deletion of the entire tree \n(Segmentation fault as no nodes to print after deletion of entire Binary tree): \n");
    printInorder(head);

    /*
    number = 13;
    insert(number, &head);
    printf("Prints the left branch's left branch: %d\n", head->left->left->data);
    */
    
    /*
    //Code Gets the left most node's value
    int store = getRightMin(head);
    printf("Data: %d\n", store);
    */
}
