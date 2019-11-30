#if 0
#include <unistd.h>
#include <stdio.h>
int global=6;
int main()
{
	pid_t pid;
	pid = fork();
	if( pid > 0 )
	{
		sleep(1);
		printf("parent : global=%d\n", global);
	}
	else if( pid == 0 )
	{
		++global;
		printf("child  : global=%d\n", global);
	}
	
	return 0;
}
#endif
#if 1
#include <unistd.h>
#include <stdio.h>
int global=6;
int main()
{
	pid_t pid;
	pid = fork();
	if( pid > 0 )
		printf("parent : global=%d\n", global);
	else if( pid == 0 )
		printf("child  : global=%d\n", global);
	
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	pid = fork();
	if( pid > 0 )
		printf("parent\n");
	else if( pid == 0 )
		printf("child\n");
	
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>
int main()
{
	fork();
	printf("after\n");
	return 0;
}
#endif
