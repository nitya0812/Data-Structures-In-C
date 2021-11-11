#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;

void insert(int data);
void deletion();
void display();
void create();

int count = 0;

void main()
{
    int no, ch, e;
    printf("MENU for Implementing Queue using Linked Lists");
    printf("\n");
    printf("1. Insert element \n");
    printf("2. Delete element \n");
    printf("3. Display queue \n");
    printf("4. Exit the program \n");
    create();
    while (1 == 1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &no);
            insert(no);
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice, please enter correct choice. ");
            break;
        }
    }

}


void create()
{
    front = rear = NULL;
}


void insert(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    printf("Traversing queue: ");
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}

void deletion()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\nError: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\nElement deleted from queue: %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\nElement deleted from queue: %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

