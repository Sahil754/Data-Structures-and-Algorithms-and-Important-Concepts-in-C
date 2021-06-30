/*Use malloc to dynamically allocate a point structure.*/

#include <stdio.h>
#include <stdlib.h>

struct point
{
    char * x;
    int y;
};

int main()
{
    struct point *p;
    
    //Malloc to dynamically allocate a point structure
    
    p = (struct point *)malloc(sizeof(struct point));
    
    p->x = "20";
    p->y = 27;
    
    printf("%s +7 = %d\n",p->x,p->y);
    
    return 0;
}






























