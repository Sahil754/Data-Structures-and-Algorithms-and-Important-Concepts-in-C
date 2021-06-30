treeNode * Delete(treeNode *node, int data)
{
    treeNode *temp;
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
