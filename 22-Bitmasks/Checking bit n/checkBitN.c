#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bit;
    int storage = 10; //1010 in binary
    bit = storage & (1 << 1);
    // storage = storage | 1 << 4;
    // storage is A , 1 << 1 is B (everything on the right of the AND(&) operator)
    printf("%d\n", storage);
     
     //Checking if it's on
     //0000001 (1)
     //0000010 (2)
     //0001010 (10)
     //0000010 (2 --> Result)
}
