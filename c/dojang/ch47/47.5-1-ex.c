#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char word[31];               // 단어를 저장할 배열
    int length;                  // 문자열 길이
    bool isPalindrome = true;    // 회문 판별값을 저장할 변수, 초깃값은 true

    printf("단어를 입력하세요: ");
    scanf("%[^\n]s", word);
	

    length = strlen(word);    // 문자열의 길이를 구함

	 int j=0,k = 0; 
    for (int i =0; i < length/2; i++ )
    {

				printf("%d %c %c \n", __LINE__, word[i + j], word[length -1 -i -k]);
			if( word[ i +j] == ' ' )
			{
				while( word[i+j] == ' ')
					j++;

				printf("%d %c %c \n", __LINE__, word[i + j], word[length -1 -i -k]);
			}
			else if( word[length -1 -i -k ] == ' ' )
			{
				while( word[length -1 -i - k] == ' ')
					k++;

				printf("%d %c %c \n", __LINE__, word[i], word[length -1 -i]);
			}
        else if (word[i + j] != word[length - 1 - i -k])
        {
            // 회문이 아님
            isPalindrome = false;
            break;
        }
				printf("%d %c %c \n", __LINE__, word[i], word[length -1 -i]);
    }

    printf("%d\n", isPalindrome);    // 회문 판별값 출력

    return 0;
}
