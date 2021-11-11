#include<stdio.h>
#include<conio.h>

struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

void main()
{
   int ch, value;
   while(1){
      printf("\n");
      printf("\n1. Push element\n2. Pop element\n3. Display stack\n4. Exit the program");
      printf("\nEnter choice from menu: ");
      scanf("%d",&ch);
      switch(ch){
	 case 1: printf("Enter the value of element to be pushed into stack: ");
		 scanf("%d", &value);
		 push(value);
		 break;
	 case 2: pop(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nError.");
      }
   }
}
void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   printf("Push operation has been performed.");
}
void pop()
{
   if(top == NULL)
      printf("\nError. Stack is empty so pop operation is not possible.");
   else{
      struct Node *temp = top;
      printf("Element that has been popped: %d", temp->data);
      top = temp->next;
      free(temp);
   }
}
void display()
{
   int count = 1;
   if(top == NULL)
      printf("\nStack is Empty");
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
	 printf("%d   ",temp->data);
	 temp = temp -> next;
      }
      printf("%d",temp->data);
   }
}
