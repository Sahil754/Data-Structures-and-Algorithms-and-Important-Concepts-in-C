#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100 // Specifying the maximum limiit of the queue

//Global declaration of variables
int queue[LIMIT];
int front, rear;

int i;
int choice;

void insert();
void delet();
void display();

int main()
{
    printf("ARRAY IMPLEMENTATION OF QUEUES\n\n");

    front = rear = -1; //Means they're empty

    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Emter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            insert();
            break;

            case 2:
            delet();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Sorry, invaid choice!\n");
            break;
        }
    } while (choice != 4);
    return 0;
}

void insert()
{
    int element;
    if (rear == LIMIT - 1) //Checks to see if the last element in the array has been reached
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        printf("Enter the element to be inserted in the queue: ");
        scanf("%d", &element);
        printf("Rear before:%d", rear);
        rear++;
        printf(", Rear after:%d\n", rear);
        queue[rear]=element;
    }
}

void delet()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow \n"); //Meaning the queue is empty
    }
    else
    {
        printf("The deleted element in the queue is: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Current Info on front & rear values: Front:%d, Rear:%d\n\nThe elements of the queue are listed below:", front, rear);
        for(i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}