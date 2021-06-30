// To remove the warnings the %x has to be changed to %p, which is normally the format code for pointers
// If you use %x or %X it's considering six positions for the address, and if you use %p it's considering 
// eight positions for the address e.g. 60FEF8 (6 positions) vs 0060FEF8 (8 positions)

#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    return 0;
}