#include <stdio.h>
#include <string.h>

int main()
{
    char text[11]; 
    int length, n;

	 scanf("%d%s", &n, text);
    length = strlen(text);    // 문자열의 길이를 구함
	
	 if ( length < n)
	 {
		printf("wrong \n");
	 }
	 else
	 {
    		for (int i = 0; i < length - (n-1); i++)
    		{
				for(int j=0; j < n; j++)
        			printf("%c", text[i + j]);    // 현재 문자와 그다음 문자 출력

				printf("\n");
    		}
	 }
    return 0;
}
