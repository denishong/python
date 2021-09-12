#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE]={0};
int _top=-1;

int IsFull()
{
		if(_top >= (MAX_STACK_SIZE-1))
				return 1;
		else
				return 0;
}

int IsEmpty()
{
		if(_top < 0)
				return 1;
		else
				return 0;
}
		
void push(int a)
{
		if(IsFull() == 1){
				printf("Stack is full!!\n");
		}else{
				stack[++_top] = a;
		}
}

int pop()
{
		if(IsEmpty())
				return -1;	
		else
				return stack[_top--];
}
int top()
{
	if(IsEmpty())
		return -1;
	else
		return stack[_top];
}

int size()
{
	int size_count=0,i;

	for(i =0; i <= _top; i++)
	{
		if( stack[i] > 0)
			size_count++;

	}
			return size_count;
}


int main()
{
		char input[10];
		int val,count;

		scanf("%d", &count);

		while(count>0)
		{
		scanf("%s", input);

		if ( !strcmp("push", input) ){
				scanf("%d", &val);
				push(val);
		}
		else if( !strcmp(input, "pop") ){
				printf("%d\n", pop() );
		}
		else if( !strcmp(input, "size") ){
				printf("%d\n", size() );
		}
		else if( !strcmp(input, "empty") ){
				printf("%d\n", IsEmpty() );
		}
		else if( !strcmp(input, "top") ){
				printf("%d\n", top() );
		}

		count--;
		
		}
		return 0;
}
