#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 10000
int stack[MAX_STACK_SIZE]={0};
int _top=-1;

void IsFull()
{
		if(_top >= (MAX_STACK_SIZE-1))
				printf("1\n");	
		else
				printf("0\n");	
}

void IsEmpty()
{
		if(_top < 0)
				printf("1\n");	
		else
				printf("0\n");	
}
		
void push(int a)
{
		if(_top >= (MAX_STACK_SIZE-1)){
				printf("Stack is full!!\n");
		}else{
				stack[++_top] = a;
		}
}

void pop()
{
		if(_top < 0)
				printf("-1\n");	
		else
				printf("%d\n",stack[_top--]);
}
void top()
{
	if(_top < 0)
		printf("-1\n");	
	else
		printf("%d\n",stack[_top]);
}

void size()
{
	int size_count=0,i;

	for(i =0; i <= _top; i++)
	{
		if( stack[i] > 0)
			size_count++;

	}
			printf("%d\n",size_count);
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
				 pop();
		}
		else if( !strcmp(input, "size") ){
				size();
		}
		else if( !strcmp(input, "empty") ){
				IsEmpty();
		}
		else if( !strcmp(input, "top") ){
				top();
		}

		count--;
		
		}
		return 0;
}
