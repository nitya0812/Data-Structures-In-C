#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int n;
    struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;

void insert_beginning();
void insert_end();
void insert_middle();
void traverse();
void delete();

int count = 0;

void main()
{
    int ch;

    h = NULL;
    temp = temp1 = NULL;

    printf("\n 1 --- Insert node at beginning");
    printf("\n 2 --- Insert node at end");
    printf("\n 3 --- Insert node at middle position");
    printf("\n 4 --- Delete node at any position");
    printf("\n 5 --- Display updated doubly linked list");
    printf("\n 6 --- Exit");

    while (1)
    {
        printf("\n Enter your choice from menu: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_beginning();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_middle();
            break;
        case 4:
            delete();
            break;
        case 5:
            traverse();
            break;
        case 6:
            exit(0);
        default:
            printf("\n Wrong choice from menu");
        }
    }
}

/* TO create an empty node */
void create()
{
    int data;

    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value of node : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}

/*  To insert at beginning */
void insert_beginning()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

/* To insert at end */
void insert_end()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

/* To insert at any position */
void insert_middle()
{
    int pos, i = 2;

    printf("\n Enter position where node is to be inserted: ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create();
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}

/* To delete an element */
void delete()
{
    int i = 1, pos;

    printf("\n Enter position where node is to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error: Position out of range to delete");
        return;
    }
    if (h == NULL)
    {
        printf("\n Error: Empty list no elements to delete");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node is deleted from doubly linked list");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node is deleted from doubly linked list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;
        if (i == 1)
            h = temp2->next;
        printf("\n Node deleted \n");
        free(temp2);
    }
    count--;
}

/* Traverse */
void traverse()
{
    temp2 = h;

    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements after traversal: \n");

    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->n);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
    printf("\n");
}

