/*This function will perform multiplication by recursively adding*/
#include <stdio.h>

//Prototype
int multiply(int x,int y);

int main()
{
    int x, y;
        printf("Please enter first number to be multiplied: ");
        scanf("%d",&x);
        
        printf("Please enter second number to be multiplied: ");
        scanf("%d",&y);
        
        printf("%d x %d = %d\n",x,y,multiply(x,y));
}

int multiply(int x,int y)
{
    if(y==1)
    {
        return x;
    }
    
    else
    {
        return x + multiply(x,y-1);
    }
}
