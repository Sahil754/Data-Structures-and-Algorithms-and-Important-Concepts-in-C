/*Define a new function called factorial() that will compute the factorial by recursive multiplication (5! = 5 x 4 x 3 x 2 x 1). Note that by convention, the factorial of 0 is equal to 1 (0! = 1).*/

#include<stdio.h>

//Prototype
int factorial(int n);

int main()
{
    //Get input from user on what factorial to calculate
    int fact;
    printf("Factorial calculator:\nPlease enter the number you would like to calculate: ");
    scanf("%d",&fact);
    
    //Printing the result of the desired factorial
    printf("The factorial of %d is: %d\n",fact,factorial(fact));
    
    return 0;
}

//Calculates factorial of a number
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}
