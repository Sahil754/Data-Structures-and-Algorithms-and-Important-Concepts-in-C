/*Write a function called birthday, which adds one to the age of a person.*/

#include <stdio.h>

int birthday(int age)
{
    //(*age)++;
    age++;
    return age;
}

int main()
{
    int age=4;
    age = birthday(age);
    printf("Age of person is: %d\n",age);
    return 0;
}
