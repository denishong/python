#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 51 
int stack[MAX_STACK_SIZE];
int _top=-1;

#define true 1
#define false 0

void initStack()
{
	_top = -1;
}

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
	int n=0,i = 0,j, check=0, count;

	while( 1 )
	{

		int i = 0, count = 0;
		char input[200];
		fgets(input, sizeof(input), stdin );

		if( input[0] == '.' ) break;

		
		//printf("input size : %ld ", strlen(input)  );
		for ( i = 0; i < strlen(input); i++ )
		{
				if ( input[i] == '(' || input[i] == '[')
				{
					push(input[i]);
				}
				else if(input[i] == ')' || input[i] == ']')
				{
					if ( get() == 0 )
					{
							count++;
						 	break;
					}else if( i !=0 && get() != 0 )
					{
						if ( get() == '(' && input[i] == ']' ){
								count++; 
								break;
						}else if ( get() == '[' && input[i] == ')' ){
								count++; 
                                break;
						}else if ( get() == '[' && input[i] == ']' ){
								pop();
						}else if ( get() == '(' && input[i] == ')' ){
								pop();
						}

					}
				}
		}


		if( IsEmpty() && count == 0 )
				printf("yes\n");
		else
				printf("no\n");

		initStack();
	}//while


		return 0;
}
