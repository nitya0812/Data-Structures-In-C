#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL, *x, *y, *z;

void create();
void ins_at_beg();
void ins_at_pos();
void del_at_beg();
void del_at_pos();
void traverse();


void main()
{
    int ch;

    printf("\n 1. Create a circular linked list \n 2. Insertion at beginning / end \n 3. Insertion at middle position");
    printf("\n 4. Deletion at beginning / end \n 5. Deletion at middle position \n 6. Display \n 7. Exit");

    while (1)
    {
        printf("\n Enter choice from menu: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            ins_at_beg();
            break;
        case 3:
            ins_at_pos();
            break;
        case 4:
            del_at_beg();
            break;
        case 5:
            del_at_pos();
            break;
        case 6:
            traverse();
            break;
        case 7:
            exit(0);
        }
    }
}

void create()
{
    int c;

    x = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &x->data);
    x->link = x;
    head = x;
    printf("\n Press 1 to continue, otherwise press 0: \n");
    scanf("%d", &c);
    while (c != 0)
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d", &y->data);
        x->link = y;
        y->link = head;
        x = y;
        printf("\n Press 1 to continue, otherwise press 0: \n");
        scanf("%d", &c);
    }
}

void ins_at_beg()
{
    x = head;
    y = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the value to be inserted in the beginning: \n");
    scanf("%d", &y->data);
    while (x->link != head)
    {
        x = x->link;
    }
    x->link = y;
    y->link = head;
    head = y;
    printf("\n Value has been inserted. \n");
}

void ins_at_pos()
{
    struct node *ptr;
    int c = 1, pos, count = 1;

    y = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("\n Enter the value to be inserted: \n");
    scanf("%d", &y->data);
    printf("\n Enter the position to insert value at: \n");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    while (ptr->link != head)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if (pos > count)
    {
        printf("OUT OF BOUND");
        return;
    }
    while (c < pos)
    {
        z = x;
        x = x->link;
        c++;
    }
    y->link = x;
    z->link = y;
    printf("\n Value has been inserted at specified position. \n");
}

void del_at_beg()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        y = head;
        while (x->link !=  head)
        {
            x = x->link;
        }
        head = y->link;
        x->link = head;
        free(y);
    }
    printf("\n Value has beginning has been deleted. \n");
}

void del_at_pos()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        int c = 1, pos;
        printf("\n Enter the position value is to be deleted from: \n");
        scanf("%d", &pos);
        x = head;
        while (c < pos)
        {
            y = x;
            x = x->link;
            c++;
        }
        y->link = x->link;
        free(x);
    }
    printf("\n Value has been deleted at specified position. \n");
}

void traverse()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        while (x->link !=  head)
        {
            printf("%d->", x->data);
            x = x->link;
        }
        printf("%d", x->data);
    }
}

