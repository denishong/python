#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int count,len,i=0,j=0;
	int gch =0;
    char A[101];
	int *al;



    scanf("%d", &count);

    while( count > 0){
    	scanf("%s",A);
		al = calloc(26, sizeof(int));
		len = strlen(A);
		for(i =0; i< len; i++ )
		{
				al[A[i]-'a']+=1;
				if( (A[i] != A[i+1] ) && (al[A[i+1]-'a'] !=0) )
					al[A[i+1]-'a']	+=300;
		}

		for(j=0; j< 26; j++){
			if( al[j] > 200 )
				break;
			else if( j == 25)
				gch++;
		}

	free(al);
    count--;
    }
        	printf("%d\n", gch);

    return 0;
}
