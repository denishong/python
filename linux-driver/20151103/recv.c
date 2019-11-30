#if 1
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void foo()
{
	sleep(3);
}
void my_sig( int signo )
{
	foo();
	printf("my_sig(%d)\n", signo );
}

int main()
{
	int i;
	signal( SIGINT, my_sig );
	while(1)
		pause();
	return 0;
}
#endif
