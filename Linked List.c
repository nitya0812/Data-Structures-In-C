#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}node_s;

node_s * head;

node_s * front(struct node *head, int add_delete)
{
	struct node *p, *sn;
	int first_data;
	if (add_delete == 0) { //Add elWement}
        printf("Enter element to add in the beginning of list: ");
        scanf("%d", &first_data);
        p=malloc(sizeof(struct node));
        p->data=first_data;
        p->next=head;
        head = p;
    } else if (add_delete == 1) { //Delete element
        p = head->next;
        head = p;}

    return head;

}

void end(struct node *head, int add_delete)
{
    struct node *p,*q, *ln;
    int last;
    if (add_delete == 0) {
        printf("Enter element to end the list\n");
        scanf("%d", &last);
        p=malloc(sizeof(struct node));
        p->data=last;
        p->next=NULL;

    }
    q=head;
    while(q->next!=NULL)
    {
            ln = q;
            q = q->next;

    }
    if (add_delete == 0) {
            q->next = p;
    } else { // Delete element
        ln->next = NULL;
        free(q);
    }

    //printlist(head);
}

void printlist(struct mode* head)
{
    struct node *q;
    int count = 0;
    q = head;
    printf("Traversing list\n");
    while (q->next != NULL)
    {
        printf("Value of element #%d is %d\n", count+1, q->data);
        q = q->next;
        count++;
    }
    //printing last element
    printf("Value of element #%d is %d\n", count+1, q->data);

}




void middle(struct node *head, int add_delete)
{
    struct node *p, *tn, *sn, *ln;
    int mid_val, mid_pos;
    if (add_delete == 0) {
        printf("Enter element to add in the middle of list: ");
        scanf("%d", &mid_val);
        printf("Enter middle position: ");
        scanf("%d", &mid_pos);
    } else {
        printf("Enter the middle position to delete: \n");
        scanf("%d", &mid_pos);
    }
    p = head;
    for (int i=0; i < mid_pos; i++){
        ln = p;
        p = p->next;
    }
    if (add_delete == 0) { //Add node
        sn = p->next;
        tn = malloc(sizeof(struct node));
        tn->data = mid_val;
        p->next = tn;
        tn->next = sn;
    } else { //Delete node
        ln->next = p->next;
    }
}

int main()
{
    struct node *prev,*p;
    int n, i, x;
    printf ("Enter number of elements in linked list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node));
        printf ("Enter element number %d: ", i+1);
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            prev->next=p;
        prev=p;
    }
    while (1 == 1)
    {
        printf("Type 1 to INSERT element at the end of linked list, 2 to insert in the beginning or 3 to insert in the middle. \n");
        printf("Type 4 to DELETE element at the end of linked list, 5 to delete in the beginning or 6 to delete in the middle. \n");
        printf("Type 7 to exit. \n");
        scanf("%d", &x);
        switch (x)
        {
            case 1 :
                end(head, 0);
                break;
            case 2 :
                head = front(head, 0);
                break;
            case 3 :
                middle(head, 0);
                break;
            case 4 :
                end(head, 1);
                break;
            case 5 :
                head = front(head, 1);
                break;
            case 6 :
                middle(head, 1);
                break;
            case 7 :
                return 0;
        }
        printlist(head);
    }



}


/*void del (struct node *head)
{
    struct node *temp;
    temp = before_del->next;
    before_del->next = temp->next;
    free(temp);
}*/



