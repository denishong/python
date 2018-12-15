#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int *firstThreadRun()
{
	while(1)
	{
		sleep(1);
		printf("start first thread\n");
	}
	return 0;
}


int *secondThreadRun()
{
	while(1)
	{
		sleep(3);
		printf("start second thread\n");
	}
	return 0;
}


int main(void)
{
	pthread_t firstThread, secondThread;
	int threadErr;

	if(threadErr = pthread_create(&firstThread, NULL, firstThreadRun, NULL))
	{
		printf("thread error= %d", threadErr);
	}


	if(threadErr = pthread_create(&secondThread, NULL, secondThreadRun, NULL))
	{
		printf("thread error= %d", threadErr);
	}

	while(1);
	return 0;
}
