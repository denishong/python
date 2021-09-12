#include <stdio.h>

#define MAX_STACK_SIZE 10000
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
		int count,val,i,total=0;

		scanf("%d", &count);

		while(count>0)
		{
			scanf("%d", &val);
			if( val > 0)
				push(val);
			else if (val == 0)
				pop();

			count--;
		
		}

		while(!IsEmpty())
		{
			total += pop();
		}

		printf("%d\n", total);

		return 0;
}
