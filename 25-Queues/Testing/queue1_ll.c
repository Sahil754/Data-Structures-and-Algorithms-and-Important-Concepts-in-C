#include <stdio.h>
#include <stdlib.h>

//Node structure for the stack
struct node
{
     int data;
     struct node *link;
} *front, *rear;

//Prototypes
void insert();
void delet();
void display();

int main()
{
    printf("LINKED LIST IMPLEMENTATION OF QUEUES\n\n");

    int choice;
    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",  &choice);

        switch (choice)
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
            printf("Sorry, invalid choice!\n");
            break;
        }
    } while(choice != 4);

    return 0;
}

void insert()
{
    struct node *temp;

    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter the element to be inserted in the queue: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (rear == NULL)
    {
        front = rear = temp;
    }

    else
    {
        rear -> link = temp;
        rear = temp;
    }
}

void delet()
{
    struct node *temp;
    temp = front;
    
    if(front == NULL)
    {
        printf("Queue underflow\n");
        front = rear = NULL;
    }

    else
    {
        printf("The deleted element from the queue is: %d\n", front->data);
        front = front->link;
        free(temp);
    }
}

void display()
{
    // Making temp pointer point to the front of the stack
    struct node *temp;
    temp = front;
    
    // Creating counter variable to loop through elements of the stack, set it to 0
    int cnt = 0;

    if(front == NULL)
    {
        printf("Queue underflow\n");
    }
    else 
    {
        printf("The elements of the stack are:\n");
        while(temp) //While temp ! = 0, since in c, any non 0 value is considered true.
        {
            printf("%d\n", temp->data);
            temp = temp->link; //Moving to the next element in the stack
            cnt++;
        }
    }
}