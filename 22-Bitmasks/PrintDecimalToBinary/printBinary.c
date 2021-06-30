#include<stdio.h>
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        int a = 1;
        int b = 0;
        (n & i) ? printf("%d", a) : printf("%d", b);
    }       
}
 
int main(void)
{   
    printf("%1s","");
    printf("0 in Binary: ");
    bin(0);
    printf("\n");
   
    printf("%1s","");
    printf("1 in Binary: ");
    bin(1);
    printf("\n");
    
    printf("%1s","");
    printf("4 in Binary: ");
    bin(4);
    printf("\n");

    //printf("%3s","");
    printf("31 in Binary: ");
    bin(31);
    printf("\n");

    //printf("%3s","");
    printf("32 in Binary: ");
    bin(32);
    printf("\n");
}