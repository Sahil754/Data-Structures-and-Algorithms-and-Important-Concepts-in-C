#include <stdio.h>
//Uninitialized name gets the value of previous name +1
int main()
{
    enum point {y = 2, x = 34, t, z = 0};
    printf("%d %d %d %d\n", x, y, z, t);
    return 0;
}
