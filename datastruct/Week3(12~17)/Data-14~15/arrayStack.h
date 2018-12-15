#pragma once
enum BOOL { FALSE, TRUE };

typedef struct _stack {
	int *stack;		/* stack으로 사용되는 동적할당 배열을 가리키는 포인터 변수 */
	int size;		/* 스택의 크기(size) */
	int top;		/* 스택의 입,출구 위치정보 저장 */
}Stack;

BOOL createStack(Stack *, int);		/* 스택 메모리 할당 및 멤버 초기화 함수 */
BOOL isStackFull(Stack *sPtr);		/* 스택이 꽉 차있는지 검사 */
BOOL isStackEmpty(Stack *sPtr);		/* 스택이 완전히 비어있는가 검사 */
BOOL push(Stack *, int);			/* 스택에 데이터 저장하는 함수 */
BOOL pop(Stack *, int *);			/* 스택에서 데이터를 꺼내는 함수 */
void printStack(const Stack*);		/* 스택 내의 모든 데이터를 출력하는 함수 */
void destroyStack(Stack *);			/* 스택 메모리 해제 함수 */
