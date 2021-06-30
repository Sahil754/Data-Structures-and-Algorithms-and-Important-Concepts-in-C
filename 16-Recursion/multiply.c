/*This function will perform multiplication by recursively adding*/
#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 1)
    {
        /* Terminating case */
        return y;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return y + multiply(x-1, y);
    }

    /* Catch scenario when x is zero */
    return 0;
}

int main() {
    
    int x, y;
        printf("Please enter first number to be multiplied: ");
        scanf("%d",&x);
        
        printf("Please enter second number to be multiplied: ");
        scanf("%d",&y);
    
    printf("%d times %d is %d\n",x,y,multiply(x, y));
    return 0;
}
