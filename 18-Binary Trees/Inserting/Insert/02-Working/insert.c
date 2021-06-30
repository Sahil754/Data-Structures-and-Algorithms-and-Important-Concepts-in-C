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
}
