#include "arrayStack.h"
#include <stdio.h>

int menu(const char **mList, size_t menuCnt);	/* 메뉴 출력 및 메뉴번호 입력 함수 */
void mInput(Stack *sp);			/* 입력메뉴 처리 함수 */
void myDelete(Stack *sp);		/* 삭제메뉴 처리 함수 */
void mOutput(Stack *sp);		/* 출력메뉴 처리 함수 */
void myflush();					/* 입력 버퍼 flush 함수 */
/*----------------------------------------------------------------------------------
Function name	: main
----------------------------------------------------------------------------------*/
int main()
{
	Stack stk;		/* 스택생성*/
	const char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" }; /* 메뉴 리스트*/
	int menuCnt;	/* 메뉴개수 저장변수*/
	int menuNum;	/* 메뉴번호 저장변수*/

	createStack(&stk, 5); /* 스택 초기화*/
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
		case 1: mInput(&stk);  break;
		case 2: myDelete(&stk); break;
		case 3: mOutput(&stk); /* stack내의 모든 데이터 출력하기*/
		}
	}
	destroyStack(&stk);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - 스택에 데이터를 반복적으로 입력함
Parameters		: sp - 스택의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void mInput(Stack *sp)
{
	int data;

	while (1) {
		printf("Push할 정수형데이터를 입력하시오(문자나 입력 시 종료) : ");
		if (scanf("%d", &data) != 1) { /* 문자가 입력되면 while문을 빠져나감*/
			myflush();
			break;
		}
		if (push(sp, data) == FALSE)
			printf("push 실패!\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: myDelete() - 스택의 데이터를 반복적으로 꺼냄
Parameters		: sp - 스택의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sp)
{
	int i;
	int cnt;		/* pop할 횟수를 입력받아 저장할 변수*/
	int popData;	/* pop한 데이터를 저장할 변수*/
	int res;		/* pop()함수의 리턴값을 저장할 변수*/

	printf("Stack에서 데이터를 pop할 횟수를 입력하시오: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = pop(sp, &popData);
		if (res == 1)  /* 성공적으로 pop 작업을수행했으면*/
		{
			printf("pop 데이터: %5d\n", popData);
		}
		else
			printf("pop 실패!\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: mOutput - 스택의 모든 데이터 출력 하기
Parameters		: sp - 스택의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void mOutput(Stack *sp)
{
	printStack(sp);
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
	size_t menuNum = 0;	/* 입력된 메뉴번호 저장 변수*/
	int res;			/* scanf()함수의 리턴값 저장 변수*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* 메뉴번호 범위내의 번호가 입력될때 까지 반복*/
	{
		printf("# 메뉴번호를 입력하세요 : ");
		res = scanf("%u", &menuNum);
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
