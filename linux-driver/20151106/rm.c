#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
// # rm    aaa     
//        argv[1]   
int main( int argc, char **argv )
{
	if( argc != 2 )
		return -1;

	unlink( argv[1] );
	return 0;
}
