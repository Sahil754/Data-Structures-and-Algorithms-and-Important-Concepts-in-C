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

NODE *search(NODE ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        free(search(&((*tree)->left), val));
    }
    else if(val > (*tree)->data)
    {
        free(search(&((*tree)->right), val));
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

int main()
{

    int number;
    NODE *head;
    head=NULL;
    NODE *tmp;

    number = 15;
    insert(number, &head); ///Doesn't need head=insert(...) anymore
    printf("prints the first element (head): %d\n", head->data);

    number = 12;
    insert(number, &head);
    printf("should print the left branch : %d\n", head->left->data);
    
    /* Search node into tree */
    tmp = search(&head, 12);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
}
