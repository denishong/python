#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char word[31];               // 단어를 저장할 배열
    int length;                  // 문자열 길이
    bool isPalindrome = true;    // 회문 판별값을 저장할 변수, 초깃값은 true

    scanf("%[^\n]s", word);
	

    length = strlen(word);    // 문자열의 길이를 구함

	 int begin =0;
	 int end = length -1;
    while ( begin < end )
    {
			while( word[begin] == ' ')
			{
					begin++;
			}

			while( word[end] == ' ')
			{
					end--;
			}

        if (word[begin] != word[end])
        {
            // 회문이 아님
            isPalindrome = false;
            break;
        }
			begin++;
			end--;
    }

    printf("%d\n", isPalindrome);    // 회문 판별값 출력

    return 0;
}
