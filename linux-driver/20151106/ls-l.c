#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	struct stat buf;
	int i;
	char perm[] = "----------";
	char rwx[] = "rwx";
	lstat( argv[1] , &buf );
	if( S_ISDIR( buf.st_mode ) )   perm[0] = 'd';
	if( S_ISLNK( buf.st_mode ) )   perm[0] = 'l';
	if( S_ISCHR( buf.st_mode ) )   perm[0] = 'c';
	if( S_ISBLK( buf.st_mode ) )   perm[0] = 'b';
	if( S_ISSOCK( buf.st_mode ) )  perm[0] = 's';
	if( S_ISFIFO( buf.st_mode ) )  perm[0] = 'p';
	for( i=0; i<9; i++ )
	{
		if( buf.st_mode & ( 1<<(8-i) ) )
			perm[1+i] = rwx[i%3];
	}

	printf("%s %s\n", perm, argv[1] );
	return 0;
}








