/*Use malloc to dynamically allocate a point structure.
 
 !!NOTE!!: The below program is simply a structure and is simply assigning and printing out the values of the structures members.
 
 It is not using malloc to dynamically allocate a point structure*/

#include <stdio.h>
//#include <stdlib.h>

struct point
{
    int x;
    int y;
};

int main()
{
    struct point p;
    p.x = 20;
    p.y = 27;
    
    printf("%s +7 = %s",p.x,p.y);
    
    return 0;
}
