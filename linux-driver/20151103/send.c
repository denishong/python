#if 1
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void foo( int pid )
{
	kill( pid, SIGINT );
}

int main( int argc, char **argv )
{
	while(1)
	{
		getchar();
		foo( atoi( argv[1] ) );
		printf("after\n");
	}
	return 0;
}
#endif
