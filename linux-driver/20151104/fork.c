#if 1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	while( waitpid(-1,0, WNOHANG) > 0 )
		;
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );

	for(j=0; j<10; j++ )
	{
		if( fork()==0 )
		{
			for(i=0; i<j+1; i++ )
			{
				sleep(1);
				printf("\t\t\tchild\n");
			}
			exit(2);
		}
	}
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	while( wait(0) > 0 )
		;
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );

	for(j=0; j<10; j++ )
	{
		if( fork()==0 )
		{
			for(i=0; i<j+1; i++ )
			{
				sleep(1);
				printf("\t\t\tchild\n");
			}
			exit(2);
		}
	}
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );

	for(j=0; j<100; j++ )
	{
		if( fork()==0 )
		{
			for(i=0; i<3; i++ )
			{
				sleep(1);
				printf("\t\t\tchild\n");
			}
			exit(2);
		}
	}
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}

int main()
{
	int i;
	signal( SIGCHLD, my_sig );
	if( fork()==0 )
	{
		for(i=0; i<3; i++ )
		{
			sleep(1);
			printf("\t\t\tchild\n");
		}
		exit(2);
	}
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i;

	if( fork()==0 )
	{
		for(i=0; i<3; i++ )
		{
			sleep(1);
			printf("\t\t\tchild\n");
		}
		exit(2);
	}
	wait(0);
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i;

	if( fork()==0 )
	{
		for(i=0; i<3; i++ )
		{
			sleep(1);
			printf("\t\t\tchild\n");
		}
		exit(2);
	}
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}

	return 0;
}
#endif
