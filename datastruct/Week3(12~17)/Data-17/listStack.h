#pragma once
enum BOOL{ FALSE, TRUE };

typedef struct _stacknode Snode;

struct _stacknode
{
	char data;		/* char 데이터 영역 */
	Snode *next;	/* 다음 노드를 가리키는 포인터 영역 */
};

typedef struct _stack	/* stack 관리 구조체 */
{
	Snode *head;	/* head pointer (head node 가리킴) */
	Snode *tail;	/* tail pointer (tail node 가리킴) */
}Stack;

BOOL createStack(Stack *sp);		/* 링크드리스트로 관리되는 스택 생성 함수 */
BOOL isStackEmpty(const Stack *sp);		/* 스택이 완전히 비어있는가 검사 */
BOOL push(Stack *sp, char pushData);	/* 스택에 데이터 저장하는 함수 */
BOOL pop(Stack *sp, char *popData);	/* 스택에서 데이터를 꺼내는 함수 */
void printStack(const Stack*sp);		/* 스택 내의 모든 데이터를 출력하는 함수 */
void destroyStack(Stack *sp);			/* 스택 메모리 해제 함수 */
