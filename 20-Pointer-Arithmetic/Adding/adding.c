// We previously increased a pointer's pointed-to address by one. 
// We can also increase it by an integer value such:

// To remove the warnings the %x has to be changed to %p, which is normally the format code for pointers
#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[1]; //point to the 2nd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 2nd element

    intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the addres of the 4th element

    return 0;
}