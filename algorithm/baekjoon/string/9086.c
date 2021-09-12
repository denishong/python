#include <stdio.h>

int main()
{

    int count,len,i=0,j=0;
    char A[101];

   	scanf("%d",&count);

	for(i =0; i<count; i++)
	{
			j=0;
			scanf("%s",A);
			while( A[j] != '\0'){
					j++;
			}
			printf("%c%c\n",A[0],A[j-1]);
	}
    return 0;
}
