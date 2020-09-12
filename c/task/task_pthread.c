#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *firstThreadRun()
{
pid_t pid;
pthread_t tid;

pid = getpid();
tid = pthread_self();

	while(1)
	{
		sleep(1);
		printf("1st thread pid: %u, tid : %lx!!\n", pid, tid);
	}
	return 0;
}

void *secondThreadRun()
{
pid_t pid;
pthread_t tid;

pid = getpid();
tid = pthread_self();
	while(1)
	{
		sleep(5);
		printf("2nd thread pid: %u, tid : %lx!!\n", pid, tid);
	}
	return 0;
}

int main(void)
{
	pthread_t firstThread,secondThread;
	int threadErr;

 	if(threadErr = pthread_create(&firstThread, NULL, firstThreadRun, NULL))
	{
		printf("1st thread error = %d", threadErr);
	}
 	if(threadErr = pthread_create(&secondThread, NULL, secondThreadRun, NULL))
	{
		printf("2nd thread error = %d", threadErr);
	}

	while(1);
	return 0;
}
