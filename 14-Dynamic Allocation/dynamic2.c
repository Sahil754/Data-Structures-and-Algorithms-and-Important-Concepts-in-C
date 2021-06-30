/*Use malloc to dynamically allocate a point structure.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char * x;
    int y;
} point;

int main()
{
    point *p;
    
    //Malloc to dynamically allocate a point structure
    
    p = (point *)malloc(sizeof(point));
    
    p->x = "20";
    p->y = 27;
    
    printf("%s +7 = %d\n",p->x,p->y);
    
    return 0;
}
