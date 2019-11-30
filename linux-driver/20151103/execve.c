#if 1
#include <unistd.h>
#include <stdio.h>
int main()
{
	char *argv[] = { "ls",  (char*)0};
	printf("prompt> ls\n");
	if( fork() == 0 )
		execve("/bin/ls", argv, 0);
	wait(0);
	printf("prompt> \n");
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
int main()
{
	char *argv[] = { "ls",  (char*)0};
	printf("prompt> ls\n");
	execve("/bin/ls", argv, 0);
	printf("prompt> \n");
	return 0;
}
#endif

#if 0
#include <stdlib.h>
int main()
{
	execlp("ls","ls", 0);
	return 0;
}
#endif

#if 0
#include <stdlib.h>
int main()
{
	system("ls");
	return 0;
}
#endif
