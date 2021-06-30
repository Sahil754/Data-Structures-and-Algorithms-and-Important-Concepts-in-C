/*Write a function called birthday, which adds one to the age of a person.*/

#include <stdio.h>

void birthday(int *age)
{
    (*age)++;
}

int main()
{
    int age=4;
    birthday(&age);
    printf("Age of person is: %d\n",age);
    return 0;
}
