#include "hash_chaining.h"
#include <stdio.h>

int menu(const char **mList, size_t menuCnt);	/* 메뉴 출력 및 메뉴번호 입력 함수 */
void mInput(CHash *sp);			/* 입력메뉴 처리 함수 */
void myDelete(CHash *sp);		/* 삭제메뉴 처리 함수 */
void mSearch(CHash *sp);		/* 검색메뉴 처리 함수 */
void myflush();					/* 입력 버퍼 flush 함수 */
/*----------------------------------------------------------------------------------
Function name	: main
----------------------------------------------------------------------------------*/
int main()
{
	CHash lhash;		/* 해시 생성*/
	const char *menuList[] = { "입력 하기", "삭제하기", "검색하기", "종료" }; /* 메뉴 리스트*/
	int menuCnt;	/* 메뉴개수 저장변수*/
	int menuNum;	/* 메뉴번호 저장변수*/

	createHash(&lhash, HASH_SIZE); /* 해시 초기화*/
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  /* 메뉴 개수 계산하기*/

	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt)  /* 종료메뉴 선택 시 반복문 탈출하기*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: mInput(&lhash);  break;
		case 2: myDelete(&lhash); break;
		case 3: mSearch(&lhash); /* hash내의 모든 데이터 출력하기*/
		}
	}
	destroyHash(&lhash); /* hash내의 모든 데이터 출력하기*/

	getchar(); getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - 해시에 데이터를 반복적으로 입력함
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void mInput(CHash *hsp)
{
	int data;

	while (1) {
		printf("저장할 정수형데이터를 입력하시오(문자나 입력 시 종료) : ");
		if (scanf("%d", &data) != 1) { /* 문자가 입력되면 while문을 빠져나감*/
			myflush();
			break;
		}
		if (hashInput(hsp, data) == FALSE)
			printf("입력 실패!\n");
		hashPrint(hsp);  // hash내 저장 상태 확인하기
	}
}
/*--------------------------------------------------------------------------------------
Function name	: myDelete() - 해시의 데이터를 삭제 함
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void myDelete(CHash *hsp)
{
	int data;
	while (1) {
		printf("삭제할 정수형데이터를 입력하시오(문자나 입력 시 종료) : ");
		if (scanf("%d", &data) != 1) { /* 문자가 입력되면 while문을 빠져나감*/
			myflush();
			break;
		}
		if (hashDelete(hsp, data) == FALSE)
			printf("삭제 실패!\n");
		hashPrint(hsp);  // hash내 저장 상태 확인하기
	}
}
/*--------------------------------------------------------------------------------------
Function name	: mSearch - 해시테이블에서 데이터 검색 하기
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void mSearch(CHash *hsp)
{
	int data;
	int hashValue;
	while (1) {
		printf("검색 정수형데이터를 입력하시오(문자나 입력 시 종료) : ");
		if (scanf("%d", &data) != 1) { /* 문자가 입력되면 while문을 빠져나감*/
			myflush();
			break;
		}
		if ((hashValue = hashSearch(hsp, data)) == -1)
			printf("검색 실패!\n");
		else
			printf("검색 성공 - 해시값 = %d\n", hashValue);

		hashPrint(hsp);  // hash내 저장 상태 확인하기
	}
}
/*--------------------------------------------------------------------------------------
Function name	: menu() - 메뉴를 출력하고 메뉴번호를 입력받아 리턴함
Parameters		: menuLIst - 메뉴출력할 문자열
				  menuCnt  - 메뉴개수
Returns			: 선택된메뉴번호
--------------------------------------------------------------------------------------*/
int menu(const char **menuList, size_t menuCnt)
{
	size_t i;
	int menuNum = 0;	/* 입력된 메뉴번호 저장 변수*/
	int res;			/* scanf()함수의 리턴값 저장 변수*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* 메뉴번호 범위내의 번호가 입력될때 까지 반복*/
	{
		printf("# 메뉴번호를 입력하세요 : ");
		res = scanf("%d", &menuNum);
		if (res != 1)  /* 정수가 입력되지 않았으면*/
		{
			myflush();  /* 입력버퍼 비우기*/
			continue;
		}
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: myflush - 입력 버퍼 내의 모든 데이터 지우는 함수
Parameters		: 없음
Returns			: 없음
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}
