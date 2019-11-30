#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
void my_ls(char *dname)
{
	DIR *dp;
	struct stat buf;
	struct dirent *p;
	chdir(dname);
	dp = opendir(".");
	while( p = readdir(dp))
	{
		printf("%s " , p->d_name );
		lstat(p->d_name, &buf);
		if( S_ISDIR( buf.st_mode ) )
		{
			if( strcmp( p->d_name, "." ) && strcmp( p->d_name, ".." )  )
			    my_ls(p->d_name);
		}
	}
	printf("\n");
	closedir(dp);
	chdir("..");
}

int main()
{
	my_ls("/root/20151106");
	return 0;
}
