
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right, *left;
} Node;

void insert (int ins, Node **start)
{
    if (*start == NULL)
    {
        //Create new node & assigning it to head
        Node *node = (Node *) malloc(sizeof(Node));
        node->data = ins;
        node->left = NULL;
        node->right = NULL;
        *start = node;
    }
    //Insert operations
    if (ins < (*start)->data)
    {
        insert(ins, &(*start)->left);
    }
    
    else if (ins > (*start)->data)
    {
        insert(ins, &(*start)->right);
    }
}

int delete(Node *p, int data)
{
    Node *q, *s, *l, *r;
    
    while(p != NULL)
    {
        q=p;
        if(data < p->data)
        {
            p=p->left;
        }
        
        else if (data > p->data)
        {
            p=p->right;
        }
        
        if(p !=NULL && data == p->data)
        {
            l=p->left;
            r=p->right;
            s=r;
            while((s != NULL) && (s->left != NULL))
            {
                s=s->left;
            }
            
            if(q->right == p)
            {
                if(r != NULL)
                {
                    q->right = r;
                }
                
                else
                {
                    q->right = l;
                }
                
                if(s != NULL)
                {
                    s->left = l;
                }
                    
                    printf("Element deleted is: %d\n", p->data);
                    free(p);
                    return 0;
            }
            else if(p->left == p)
            {
                q->left = l;
                while((l != NULL) && (l->right != NULL))
                {
                    l=l->right;
                }
                
                if(l != NULL)
                {
                    l->right = r;
                }
                
                printf("Element deleted is: %d\n", p->data);
                free(p);
                return 0;
            }
            else
            {
                if(r != NULL)
                {
                    p = r;
                    s->left = l;
                }
                
                else
                {
                    p = l;
                }
                
                printf("Element deleted is: %d\n", p->data);
                free(p);
                return 0;
            }
        }
    }
    return 0;
}


int main()
{
    int number;
    Node *head = NULL;
    
    number = 15;
    insert(number, &head);
    printf("The root value of the Binary tree is: %d\n", head->data);
    
    number = 12;
    insert(number, &head);
    printf("The left child of the root's value is: %d\n", head->left->data);
    
    head = delete(head, 12);
    printf("The root value of the Binary tree is: %d\n", head->data);
    printf("The left child of the root's value is: %d\n", head->left->data);

}
