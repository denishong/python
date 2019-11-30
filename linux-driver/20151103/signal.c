#if 1
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void my_sig( int signo )
{
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
#if 0
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
}

int main()
{
	int i;
	sigset_t set, oldset;
	sigemptyset( &set );
	sigemptyset( &oldset );
	sigaddset( &set, SIGINT );
	signal( SIGINT, my_sig );
	sigprocmask(SIG_BLOCK, &set, &oldset);
	for(i=0; i<3; i++)
	{
		sleep(1);
		printf(".\n");
	}
	sigprocmask(SIG_SETMASK, &oldset, 0);
	while(1)
		pause();
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
}

int main()
{
	int i;
	signal( SIGINT, my_sig );
	for(i=0; i<3; i++)
	{
		sleep(1);
		printf(".\n");
	}
	while(1)
		pause();
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
}

int main()
{
	signal( SIGINT, my_sig );
	while(1)
		pause();
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <signal.h>
int main()
{
	signal( SIGINT, SIG_IGN );
	signal( SIGQUIT, SIG_IGN );
	signal( SIGKILL, SIG_IGN );
	while(1)
		pause();
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <signal.h>
int main()
{
	signal( SIGINT, SIG_IGN );
	while(1)
		pause();
	return 0;
}
#endif

#if 0
#include <unistd.h>
int main()
{
	while(1)
		pause();
	return 0;
}
#endif
