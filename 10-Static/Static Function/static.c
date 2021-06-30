/*Adds given number together, and continues to add subsequent numbers to the previously given numbers*/

#include<stdio.h>

int sum(num)
{
    static int total = 0;
    total += num;
    return total;
}

int main()
{
    printf("The current total is: %d\n", sum(10));
    printf("The current total is: %d\n", sum(10));
    printf("The current total is: %d\n", sum(10));
    
    /* Why does the following give the error if total is static and accesable throughout this file? :
     
     static.c:19:41: error: use of undeclared identifier 'total'
         printf("The current total is: %d\n",total);
                                             ^
     1 error generated.
     
     sum(10);
    printf("The current total is: %d\n",total);*/
    
	return 0;
}
