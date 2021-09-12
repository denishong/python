#include <stdio.h>


int main()
{
    int i,j,x,y, count = 0;
    char chess[51][51]={0,};

/*input chess colum, row size */
    scanf("%d %d", &x, &y);

/*input chess pattern in according to xy */
    for(i=0; i<x; i++)
        scanf( "%s", chess[i] );

    for(i=0; i<x; i++)
	{
        for(j=0; j<y; j++){
            printf("%c", chess[i][j]);
		}
	printf("\n");
	}

    return 0;
}
