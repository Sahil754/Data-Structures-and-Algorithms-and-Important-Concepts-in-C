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



    int storage = 16; //
    storage ^= 1 << 4;
    // storage = storage ^ 1 << 4;
    // storage is A , 1 << 4 is B (everything on the right of the XOR(^) operator)
    printf("%d\n", storage);
    // 0000001 (1)
    //0010000 (16)
    //0010000 (16)
    //0000000 (0)
}