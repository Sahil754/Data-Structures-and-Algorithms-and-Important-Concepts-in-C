/*static is a keyword in the C programming language. It can be used with variables and functions.
 
 By default, variables are local to the scope in which they are defined. Variables can be declared as static to increase their scope up to file containing them. As a result, these variables can be accessed anywhere inside a file.
*/
#include<stdio.h>


int runner() {
    int count = 0;
    count++;
    return count;
}

int main()
{
    printf("%d \n", runner());
    printf("%d \n", runner());
    printf("%d \n", runner());
    return 0;
}
