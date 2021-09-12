#include <stdio.h>
#include <string.h>

int main()
{

	int count,repeat,i=0,j=0;
	char S[26]={-1,};
	char str[101];

	scanf("%s", str);
	
	for( i='a'-'a'; i<='z'-'a'; i++){
		S[i] = -1;
	}

	
	while(str[j] != '\0'){
		if( S[str[j] - 'a'] == -1)
		S[str[j]-'a'] = j;

		str[j];
		j++;
	}

	for( i='a'-'a'; i<='z'-'a'; i++)
		printf("%d ",S[i] );
	
	return 0;
}
