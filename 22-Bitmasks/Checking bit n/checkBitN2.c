#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bit;
    int storage = 10; //1010 in binary
    int test = (1 << 2);
    printf("%d\n", test);
    bit = storage & test; //(1 << 2);
    // storage = storage | 1 << 4;
    // storage is A , 1 << 1 is B (everything on the right of the AND(&) operator)
    printf("%d\n", bit);
     //Checking if it's off
     //0000001 (1)
     //0000100 (12)
     //0001010 (10)
     //0000000 (0 --> Result)

     return 0;
}
