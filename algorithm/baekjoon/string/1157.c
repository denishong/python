#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	int count,repeat,i=0,j=0;
	int max=0;
	int *S = calloc(26, sizeof(int));
	char str[1000001]={0};
	char ch;
	int check_max=0;

	scanf("%s", str);
	count = strlen(str);

	for(i =0; i < count; i++){
		if( 'A' <= str[i] && str[i] <= 'Z')
		S[str[i]-'A']++;
		else if( 'a' <= str[i] && str[i] <= 'z')
		S[str[i]-'a']++;
	}

	for( j=0; j<26; j++)
	{
		if( S[j] > max)
			max = S[j];

	}

	for( j=0; j<26; j++)
	{
		if( S[j] == max){
			check_max++;
			ch = j+'A';
			}

		if( check_max >=2)
			ch = '?';
	}

	free(S);
	printf("%c\n",ch );
	return 0;
}
