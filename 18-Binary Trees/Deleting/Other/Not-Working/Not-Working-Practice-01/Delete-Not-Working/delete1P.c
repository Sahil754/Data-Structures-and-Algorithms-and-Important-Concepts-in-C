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

//find min node in BST
NODE FindMin(NODE * p)
{
    NODE *temp = p;
    
    if(p == NULL)
    {
        return -1;
    }
    else
    {
        NODE *temp = p;
        //in a balanced BST the minimum node is the leftmost node so,
        //we traverse the left subtree until we get to the leftmost node and return and remove it.
        temp = p;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
}

NODE * Delete(NODE *node, int data)
{
    NODE *temp;
    if(node==NULL)
      {
        printf("Element Not Found");
      }
    else if(data < node->data)
      {
        node->left = Delete(node->left, data);
      }
    else if(data > node->data)
      {
        node->right = Delete(node->right, data);
      }
    else
      {
    /* Now We can delete this node and replace with either minimum element
               in the right sub tree or maximum element in the left subtree*/
        if(node->right && node->left)
          {
        /* Here we will replace with minimum element in the right sub tree */
            temp = FindMin(node->right);
            node -> data = temp->data;
    /* As we replaced it with some other node, we have to delete that node */
            node -> right = Delete(node->right,temp->data);
          }
        else
           {
        /* If there is only one or zero children then we can directly
                       remove it from the tree and connect its parent to its child */
            temp = node;
             if(node->left == NULL)
                    node = node->right;
             else if(node->right == NULL)
                    node = node->left;
            free(temp); /* temp is longer required */
            }
    }
    return node;

}


int main()
{

    int number;
    NODE *head;
    head=NULL;

    number = 15;
    insert(number, &head); ///Doesn't need head=insert(...) anymore
    printf("prints the first element (head): %d\n", head->data);

    number = 12;
    insert(number, &head);

    printf("should print the left branch : %d\n", head->left->data);
    
    //head = Delete(head, 12);
}
