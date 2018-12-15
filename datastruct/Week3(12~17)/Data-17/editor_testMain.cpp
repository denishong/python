#include "liststack.h"
#include <stdio.h>

int main()
{
	Stack lstk, rstk;     /* 왼쪽, 오른쪽 스택 생성*/
	FILE *fp;
	char ch;
	int i;
	int cmdCnt;  /* 명령어 개수 저장 변수 */

	createStack(&lstk); /* 스택초기화*/
	createStack(&rstk); /* 스택초기화*/

	fp = fopen("d:\\data\\editor1.txt", "rt");
	if(fp==NULL){
		printf("파일 오픈 에러!!\n");
		getchar();
		return 1;
	}

	// TODO

	fclose(fp);
	getchar();
	return 0;
}
