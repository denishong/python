#include <stdio.h>

int main()
{

    int count,len,i=0,j=0;
    char A[101];

   	scanf("%s",A);
    while( A[i] != '\0'){
		for(j =0; j< 10; j++ ){
			
    		if( A[i] == '\0')
				break;
			printf("%c",A[i] );
    		i++;
		}
		printf("\n");
    }

    return 0;
}
