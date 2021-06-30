#include <stdio.h>
//Error: Enumerator value for 'y' is not an integer constant
//"error: expression is not an integer constant expression"
//As defining y as 2.5, which is a float and not an integer constant

int main()
{
    enum point {x = 34, y = 2.5, z = 0};
    printf("%d %d %d", x, y, z);
    return 0;
}
