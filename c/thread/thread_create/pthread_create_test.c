#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//thread function
void *test(void *data)
{
	int i;
	int a=*(int *)data;
	for(i=0; i<10; i++)
		printf("%d\n", i*a);

	return (void *)(i*100);
}

int main(void)
{
	int a =100;
	pthread_t thread_t;
	int status;

	//create thread
	if(pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
	{
		perror("thread create error:");
		exit(0);
	}

	//wait for thread to exit
	//print return value of thread

	pthread_join(thread_t, (void **)&status);
	printf("Thread End %d\n", status);
	return 1;
}
