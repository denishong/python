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
	int n=0,i,j, check=0, count;
	char input[200];


	scanf("%[^.]s", input);

	while(input[0] != '.' && input[1] !=0)
	{
			i = 0;
			_top = -1;
		//input = calloc(200, sizeof(char) );
		while( input[i] != '.')
		{
				if ( input[i] == '(' || input[i] == '[')
					push(input[i]);
				else if(input[i] == ')' || input[i] == ']')
				{
					if( i == 0)
					{
						push(input[i]);
						break;
					}else if( i !=0 && get() ==-1)
					{
						push(input[i]);
						break;
					}else if( i !=0 && get() != -1)
					{
						if ( get() == '(' && input[i] == ']' ){
								break; 
						}else if ( get() == '[' && input[i] == ')' ){
								break; 
						}else if ( get() == '[' && input[i] == ']' ){
								pop();
						}else if ( get() == '(' && input[i] == ')' ){
								pop();
						}

					}
				}
		i++;
		}



		if( IsEmpty() )
				printf("yes\n");
		else
				printf("no\n");

		getchar();
		input[1] = 0;
		scanf("%[^.]s", input);
		//free(input);
	}//while


		return 0;
}
