#include <stdio.h>
#include <string.h>

int main()
{

	int count,repeat,i,j;
	char A[101];

	scanf("%d", &count);

	while( count > 0){
	scanf("%d %s",&repeat, &A[0]);
	for( i=0; i<strlen(A); i++)
		for( j=0; j<repeat; j++)
			printf("%c", A[i]);

		printf("\n");

	count--;
	}

	return 0;
}
