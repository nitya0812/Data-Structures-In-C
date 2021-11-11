#include<stdio.h>
#include<conio.h>

#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

void main()
{
   int value, ch;
   while(1){
      printf("\n");
      printf("\n1. Push element\n2. Pop element\n3. Display stack\n4. Exit the program");
      printf("\nEnter choice from menu: ");
      scanf("%d",&ch);
      switch(ch){
	 case 1: printf("Enter the value of element to be pushed into stack: ");
		 scanf("%d",&value);
		 push(value);
		 break;
	 case 2: pop();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nError.");
      }
   }
}
void push(int value){
   if(top == SIZE-1)
      printf("\nError. Stack is full so push operation is not possible.");
   else{
      top++;
      stack[top] = value;
      printf("Push operation has been performed.");
   }
}
void pop(){
   if(top == -1)
      printf("\nError. Stack is empty so pop operation is not possible.");
   else{
      printf("\nElement that has been popped: %d", stack[top]);
      top--;
   }
}
void display()
{
   if(top == -1)
      printf("\nStack is Empty.");
   else{
      int i;
      printf("\nTraversing stack...\n");
      for(i=top; i>=0; i--)
	 printf("%d   ", stack[i]);
   }
}
