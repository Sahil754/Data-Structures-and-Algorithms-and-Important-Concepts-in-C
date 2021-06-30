#include <stdio.h>
#include <stdlib.h>

void push(); // Function used to insert the element into the stack
void pop(); // Function used to delete the elememt from the stack
void display(); // Function used to display all the elements in the stack according to LIFO rule

struct node
{
    int data;
    struct node *next;
};

struct node *temp;

int main()
{
    printf("Welcome to DataFlair tutorials!\n\n");
    int choice;
    printf ("LINKED LIST IMPLEMENTATION USING STACKS\n\n");
    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;
            
            default:
            printf("Sorry, invalid choice!\n");
            break;
        }
    } while(choice!=4);
    return 0;
}