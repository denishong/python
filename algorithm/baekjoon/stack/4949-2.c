#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 51 
int stack[MAX_STACK_SIZE];
int _top=-1;

#define true 1
#define false 0

int IsFull()
{
		if(_top >= MAX_STACK_SIZE-1)
				return true;
		else
				return false;
}

int IsEmpty()
{
		if(_top < 0)
				return true;
		else
				return false;
}
		
void push(int a)
{
		if(IsFull())
				printf("Stack is full!!\n");
		else
				stack[++_top] = a;
}

int pop()
{
		if(IsEmpty())
				return -1;	
		else
				return stack[_top--];
}
int get()
{
		if(IsEmpty())
				return -1;	
		else
				return stack[_top];
}

int top()
{
		return _top;
}

int size()
{
		return _top;
}


int main()
{
		int i=0,j, check=0, count;
		char *input = "So delicious";


		//scanf("%[^.]s", input);

		while( input[i] != '\0')
		{
			printf("%c", input[i] );
			i++;

		}




		return 0;
}
