#include <stdio.h>

#define MAX_N 100

int front;
int rear;
int queue[MAX_N];

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if( (rear = 1) % MAX_N == front )
	{
		return 1;
	}
	else{
		return 0;
	}
}

int queueIsEmpty()
{
	return (front == rear);
}

int queueEnqueue( int x)
{

	if( queueIsFull() )
	{
		printf("queue is full!\n");
		return 0;
	}
	queue[rear] = x;
	rear++;

	if( rear == MAX_N)
		rear = 0;

	return 1;
}

int queueDequeue(int *value)
{

	if( queueIsEmpty() )
	{
		printf("queue is empty!!\n");
		return 0;
	}

	*value = queue[front];
	front++;

	if( front == MAX_N )
	{
		return 0;
	}
	return 1;
}

int push(int x)
{
	queue[++] = x;

}


int main()
{


	return 0;
}
