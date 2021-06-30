#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    int storage = 66;
    storage |= 1 << 4;
    // storage = storage | 1 << 4;
    //printf("%d\n", storage);
    printf("%d\n",1 << 4);
    // 1010010 (82)
    // 0000001
    //0000010
*/

// Clearing bit n 

    int storage = 20; //0000000000010100
    storage &= ~(1 << 2);
    // storage = storage & ~(1 << 2);
    // storage is A , ~(1 << 2) is B (everything on the right of the AND(&) operator)
    printf("%d\n", storage);
    //  0000000000000001(1)
     //0000001 (1)
     //0000010 (2)
     //0010000 (Result, represents 16 in decimal)
}
