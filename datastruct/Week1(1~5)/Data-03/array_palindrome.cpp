
#include <stdio.h>
#include <string.h>

void inputString(char *cp);
int checkPalindrome(char *cp);

int main()
{
	char str[80];		// 문자열 저장 배열
	int res;			// 회문 검사 결과 저장

	inputString(str);
	while(strcmp(str,"end")!=0){
		res = checkPalindrome(str);
		if(res==1)
			printf("\"%s\" : 회문입니다.\n", str);
		else
			printf("\"%s\" : 회문이 아닙니다.\n", str);
		inputString(str);
	}

	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
void inputString(char *cp)
{
	printf("# 회문 검사할 문자열을 입력하시오 : ");
	scanf("%s", cp);
	return;
}
//---------------------------------------------------
int checkPalindrome(char *cp)
{
	// TODO
	return 0;
}