#include <stdio.h>

int main()
{
    char name[100][30];
    
    int i, n;

    printf("Enter The Limit : ");
    scanf(" %d", &n);

    for(i = 0; i < n; i++)
    {
        scanf(" %[^\n]", &name[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("\n %s", &name[i]);
    }

    return 0;
}