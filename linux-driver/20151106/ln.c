#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
// # ln    aaa      bbb
//        argv[1]   argv[2]
int main( int argc, char **argv )
{
	if( argc != 3 )
		return -1;

	link( argv[1], argv[2] );
	return 0;
}
