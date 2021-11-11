//Queue using Arrays

#include <stdio.h>
#include <conio.h>
#define MAX 50

void insert();
void delete();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int ch;
    printf("MENU for Implementing Queue using Arrays \n");
    while (1 == 1)
    {
        printf("\n");
        printf("1. Insert element at rear \n");
        printf("2. Delete element at front \n");
        printf("3. Display queue \n");
        printf("4. Exit the program \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        }
    }
}

void insert()
{
    int append;
    if (rear == MAX - 1)
    printf("Overflow condition for queue \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Element to insert in queue: ");
        scanf("%d", &append);
        rear = rear + 1;
        queue_array[rear] = append;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Underflow condition for queue \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Traversing queue: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
