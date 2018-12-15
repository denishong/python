#include "listStack.h"
#include <stdio.h>
#include <malloc.h>
/*--------------------------------------------------------------------------------------
Function name	: createStack - 링크드리스트로 관리되는 스택 생성 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
--------------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	sp->head = (Snode *)calloc(1, sizeof(Snode)); /* 헤드 노드 생성	*/
	if (sp->head == NULL) {
		return FALSE;
	}
	sp->tail = (Snode *)calloc(1, sizeof(Snode)); /* 테일 노드 생성 */
	if (sp->tail == NULL) {
		free(sp->head);
		return FALSE;
	}
	/* 헤드노드가 테일노드를, 테일노드가 테일노드를 가리키게 함 */
	sp->head->next = sp->tail;
	sp->tail->next = sp->tail;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: isStackEmpty() - 스택이 비어있는가 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 완전히 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isStackEmpty(const Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}

	if (sp->head->next == sp->tail)
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push() - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택관리 구조체의 주소
				  pushData  - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, char pushData)
{
	Snode *cur;			/* 작업용 Snode 포인터 선언 */
	if (sp == NULL) {	/* sp포인터 NULL check*/
		return FALSE;
	}

	cur = (Snode *)calloc(1, sizeof(Snode));	/* 새로운 노드 생성 */
	if (cur == NULL){		/* 메모리 할당 실패하면 push실패 */
		return FALSE;
	}
	else {					/* 새 노드를 head node 바로 뒤에 노드 추가 */
		cur->next = sp->head->next;
		sp->head->next = cur;
		cur->data = pushData; /* 새 노드의 데이터 영역에 데이터 복사 */
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: pop() - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택관리 구조체의 주소
popData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL pop(Stack *sp, char *popData)
{
	Snode *cur;			/* 작업용 Snode 포인터 선언 */
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}

	if (isStackEmpty(sp) == TRUE){	/* stack이 비어있으면 pop실패 */
		return FALSE;
	}
	else {		/* head node 뒤에서 데이터를 꺼낸 후 데이터 노드 삭제 */
		*popData = sp->head->next->data;
		cur = sp->head->next;
		sp->head->next = sp->head->next->next;
		free(cur);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - 스택의 모든 데이터 출력(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack *sp)
{
	Snode *cur;			/* 작업용 Snode 포인터 선언 */
	if (sp == NULL) {	/* sp포인터 NULL check*/
		return;
	}

	if (isStackEmpty(sp) == TRUE)
	{
		printf("Stack이 비어있습니다!!\n");
		return;
	}
	cur = sp->head->next;
	while (cur != sp->tail)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack() - 스택 소멸 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	Snode *cur;			/* 작업용 Snode 포인터 선언 */
	if (sp == NULL) {	/* sp포인터 NULL check*/
		return;
	}
	/* 데이터 첫 노드부터 맨 뒤의 노드까지 모두 삭제 */
	while (sp->head->next != sp->tail)
	{
		cur = sp->head->next;
		sp->head->next = sp->head->next->next;
		free(cur);
	}
	free(sp->head);	/* 헤드노드 삭제 */
	free(sp->tail);	/* 테일노드 삭제 */
	sp->head = sp->tail = NULL; /* head, tail 포인터를 NULL로 초기화 */

	return;
}
