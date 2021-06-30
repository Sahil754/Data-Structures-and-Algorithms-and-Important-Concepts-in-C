int delete(struct tree *p, int value)
{
    struct *q, *s, *l, *r;
    
    while(p != NULL)
    {
        q=p;
        if(value < p->data)
        {
            p=p->left;
        }
        
        else if (value > p->data)
        {
            p=p->right;
        }
        
        if(p !=NULL && value == p->data)
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
                    q->right = 1;
                }
                
                if(s != NULL)
                {
                    s->left = 1;
                }
                    
                    printf("Element deleted is: %d\n", p->value);
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
                
                printf("Element deleted is: %d\n", p->value);
                free(p);
                return 0;
            }
            else
            {
                if(r != NULL)
                {
                    root = r;
                    s->left = l;
                }
                
                else
                {
                    root = l;
                }
                
                printf("Element deleted is: %d\n", p->value);
                free(p);
                return 0;
            }
        }
    }
    return 0;
}
