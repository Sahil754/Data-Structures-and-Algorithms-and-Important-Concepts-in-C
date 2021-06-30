/*Create a pointer to the local variable n called pointer_to_n, and use it to increase the value of n by one.*/

#include <stdio.h>

int main()
{
    int n;
    n = 2;
    
    int *pointer_to_n;
    pointer_to_n = &n;
    
    *pointer_to_n+=1;
    
    /* testing code */
      if (pointer_to_n != &n) return 1;
      if (*pointer_to_n != 11) return 1;
    
    printf("The value of n is: %d\n",*pointer_to_n);
    /*
     Tried this also, but didn't work:
     printf("The value of n is: %d\n",pointer_to_n);
     */
    return 0;
}
