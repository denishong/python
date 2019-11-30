#include <stdio.h>
#include <fcntl.h>
// # cp    aaa      bbb
//        argv[1]   argv[2]
int main( int argc, char **argv )
{
	int src, dst, ret;
	char buff[4096];

	if( argc != 3 )
		return -1;

	src = open( argv[1], O_RDONLY );
	dst = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666 );
	while( ret = read( src, buff, sizeof buff ) )
		write( dst, buff, ret );
	close(src);
	close(dst);
	return 0;
}
