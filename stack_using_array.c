#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX], top = -1;
void push(int data)
{
  if(top == MAX - 1)
    printf("Overflown\n");
  else
    stack[++top] = data;
}

void pop()
{
  if(top == -1)
    printf("Underflown\n");
  else
{
  int item = stack[top];
  top--;
  printf("Popped element is %d", item);
}
}

void peek()
{
	if(top == -1)
		printf("Stack Empty\n");
	else
		printf("Top element is %d", stack[top]);
}

void isEmpty()
{
	if(top == -1)
		printf("Stack Empty\n");
	else
		printf("Stack is not empty\n");
}
	
void isFull()
{
	if(top == MAX-1)
		printf("Stack Full\n");
	else
		printf("Stack is not full\n");
}

void display()
{
	for(int i = top;i > 0; i ++)
	{
		printf("%d", stack[i]);
		printf("\n");
	}
}

void main()
{
	int ch;
	do
	{
		int data;
		printf("1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.isFull\n6.Display\n7.exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("Enter element to be pushed: ");
					scanf("%d", data);
					push(data);
					break;
			
			case 2: pop();
					break;
					
			case 3: peek();
					break;
					
			case 4: isEmpty();
					break;
					
			case 5: isFull();
					break;
					
			case 6: display();
					break;
					
			case 7: printf("Exit");
					exit(0);
					break;
					
			default: printf("Wrong choice!");
					 break;	
		}
	}while(ch<=6);
