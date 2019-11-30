#if 1
#include <fcntl.h>
#include <stdlib.h>

int main( int argc, char ** argv )
{
	int fd, ret;
	char buff[4096];

	fd = open( argv[1], O_RDONLY);
	if( fork() == 0 )
	{
		read( fd, buff, 2 );
		write( 1, buff, 2 );
		sleep(100);
		close(fd);
		exit(0);
	}
	sleep(1);
	read( fd, buff, 2 );
	write( 1, buff, 2 );
	getchar();
	close(fd);
	return 0;
}

#endif
#if 0
#include <fcntl.h>
#include <stdlib.h>

int main( int argc, char ** argv )
{
	int fd, ret;
	char buff[4096];

	if( fork() == 0 )
	{
		fd = open( argv[1], O_RDONLY);
		read( fd, buff, 2 );
		write( 1, buff, 2 );
		sleep(100);
		close(fd);
		exit(0);
	}
	fd = open( argv[1], O_RDONLY);
	sleep(1);
	read( fd, buff, 2 );
	write( 1, buff, 2 );
	getchar();
	close(fd);
	return 0;
}

#endif
#if 0
#include <fcntl.h>

int main( int argc, char ** argv )
{
	int fd[2], ret;
	char buff[4096];

	fd[0] = open( argv[1], O_RDONLY);
	fd[1] = open( argv[1], O_RDONLY);

	read( fd[0], buff, 2 );
	write( 1, buff, 2 );

	read( fd[1], buff, 2 );
	write( 1, buff, 2 );

	close(fd[0]);
	close(fd[1]);
	return 0;
}

#endif
#if 0
#include <fcntl.h>

int main( int argc, char ** argv )
{
	int fd, ret;
	char buff[4096];

	fd = open( argv[1], O_RDONLY);
	read( fd, buff, 2 );
	write( 1, buff, 2 );

	read( fd, buff, 2 );
	write( 1, buff, 2 );

	close(fd);
	return 0;
}

#endif
#if 0
#include <fcntl.h>

int main( int argc, char ** argv )
{
	int fd, ret;
	char buff[4096];

	fd = open( argv[1], O_RDONLY);
	while( ret = read( fd, buff, sizeof buff ) )
		write( 1, buff, ret );

	close(fd);
	return 0;
}

#endif
#if 0
#include <fcntl.h>

int main( int argc, char ** argv )
{
	int fd;
	char ch;

	fd = open( argv[1], O_RDONLY);
	while( read( fd, &ch, 1 ) )
		write( 1, &ch, 1 );

	close(fd);
	return 0;
}

#endif
#if 0
#include <stdio.h>

int main( int argc, char ** argv )
{
	FILE *fp;
	int ch;
	int count=0;

	fp = fopen( argv[1], "r" );
	while( (ch = fgetc(fp))  != EOF )
		count++;

	printf("size=%d\n", count );
	fclose(fp);
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main( int argc, char ** argv )
{
	FILE *fp;
	int ch;

	fp = fopen( argv[1], "r" );
	while( (ch = fgetc(fp))  != EOF )
		fputc( ch, stdout );

	fclose(fp);
	return 0;
}
#endif
