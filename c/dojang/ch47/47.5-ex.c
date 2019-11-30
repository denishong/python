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

	 printf("length : %d\n", length);
    
    // 0부터 문자열 길이의 절반만큼 반복
	 int j=0,k = 0; 
    for (int i =0; i < length/2; i++ )
    {

		printf("%d %c %c \n",__LINE__, word[i + j], word[ length -1 -i -k] );

			if( word[ i +j] == ' ' )
			{
				j++;
			}
			else if( word[ length -1 -i -k] == ' ' )
			{
				k++;
			}
        else if (word[i + j] != word[length - 1 - i -k])
        {
            // 회문이 아님
            isPalindrome = false;
            break;
        }
    }

    printf("%d\n", isPalindrome);    // 회문 판별값 출력

    return 0;
}
