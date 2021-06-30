#include <stdio.h>
//Redefining a name within the same scope not
//allowed
int main()
{
    enum point1 {x = 34, y = 2, z = 0};
    enum point2 {x = 4, p = 25, q = 1};
    printf("%d %d %d %d %d", x, y, z, p, q);
    return 0;
}
