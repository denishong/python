#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *firstThreadRun()
{
	while(1)
	{
		usleep(1000000);
		printf("start first thread\n");
	}
	return 0;
}


void *secondThreadRun()
{
	while(1)
	{
		sleep(3000000);
		printf("start second thread\n");
	}
	return 0;
}

void *thirdThreadRun()
{
   while(1)
   {   
      sleep(5000000);
      printf("start third thread\n");
   }   
   return 0;
}
void *fourthThreadRun()
{
   while(1)
   {   
      sleep(8000000);
      printf("start fourth thread\n");
   }   
   return 0;
}

int main(void)
{
	pthread_t firstThread, secondThread,thirdThread,fourthThread;
	int threadErr;

	if(threadErr = pthread_create(&firstThread, NULL, firstThreadRun, NULL))
	{
		printf("thread error= %d", threadErr);
	}


	if(threadErr = pthread_create(&secondThread, NULL, secondThreadRun, NULL))
	{
		printf("thread error= %d", threadErr);
	}

   if(threadErr = pthread_create(&thirdThread, NULL, thirdThreadRun, NULL))
   {
      printf("thread error= %d", threadErr);
   }

   if(threadErr = pthread_create(&fourthThread, NULL, fourthThreadRun, NULL))
   {
      printf("thread error= %d", threadErr);
   }

	while(1);
	return 0;
}
