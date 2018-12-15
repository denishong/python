#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "listQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - 큐 초기화 함수
Parameters		: qp - 큐 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
--------------------------------------------------------------------------------------*/
BOOL createQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp 포인터 NULL check */
		return FALSE;
	}

	qp->head = (Node *)calloc(1, sizeof(Node));	/* 헤드 노드 생성 */
	if (qp->head == NULL) {
		return FALSE;
	}
	qp->tail = (Node *)calloc(1, sizeof(Node));	/* 테일 노드 생성 */
	if (qp->tail == NULL) {
		free(qp->head);
		return FALSE;
	}
	else { /* 헤드노드가 테일노드를, 테일노드가 테일노드를 가리키게 함 */
		qp->head->next = qp->tail;
		qp->tail->next = qp->tail;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - 큐가 비어있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns			: 완전히 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp 포인터 NULL check */
		return FALSE;
	}
	/* 큐가 완전히 비어있으면 TRUE, 아니면 FALSE 리턴 */
	if (qp->head->next == qp->tail)
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue - 큐에 데이터 하나를 저장함
Parameters		: qp - 큐 구조체의 주소
				  enqueData - 큐에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL enqueue(Queue * qp, int enqueData)
{
	Node *cur;
	if (qp == NULL) {  /* qp 포인터 NULL check */
		return FALSE;
	}

	Node *np = (Node *)calloc(1, sizeof(Node)); /* 새로운 노드 생성 */
	if (np == NULL)		/* 메모리 할당 실패하면 enqueue실패 */
	{
		return FALSE;
	}
	/* 노드를 테일 노드 바로 앞에 노드 추가 */
	cur = qp->head;
	while (cur->next != qp->tail)  /* 테일 노드 바로 앞노드를 cur로 가리키게 이동 시킴 */
		cur = cur->next;

	cur->next = np;
	np->next = qp->tail;
	np->data = enqueData;	/* 데이터 복사 */

	return TRUE;

}
/*--------------------------------------------------------------------------------------
Function name	: dequeue - 큐에서 데이터 하나를 꺼냄
Parameters		: qp - 큐 구조체의 주소
				  dequeData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, int * dequeData)
{
	Node *cur;
	if (qp == NULL) {  /* qp 포인터 NULL check */
		return FALSE;
	}

	if (isQueueEmpty(qp))	/* 큐가 비어있으면 dequeue 불가 */
	{
		return FALSE;
	}
	else {	/* head node 뒤에서 데이터를 꺼낸 후 데이터 노드 삭제 */
		*dequeData = qp->head->next->data;
		cur = qp->head->next;
		qp->head->next = qp->head->next->next;
		free(cur);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue - 큐 내의 모든 데이터를 출력 함
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	Node *cur;
	if (qp == NULL) {  /* qp 포인터 NULL check */
		return;
	}

	if (isQueueEmpty(qp) == TRUE)
	{
		printf("Queue가 비어있습니다!!\n");
		return;
	}
	/* dequeue 순서대로 출력하기 - 실제로 dequeue 되는 것은 아님 */
	cur = qp->head->next;
	while (cur != qp->tail) {
		printf("%5d\n", cur->data);
		cur = cur->next;
	}
	printf("\n\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue - 큐 소멸 함수
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	Node *cur;
	if (qp == NULL) {  /* qp 포인터 NULL check */
		return;
	}
	/* 데이터 첫 노드부터 맨 뒤의 노드까지 모두 삭제 */
	cur = qp->head->next;
	while (cur != qp->tail) {
		qp->head->next = qp->head->next->next;
		free(cur);
		cur = qp->head->next;
	}
	free(qp->head);	/* 헤드노드 삭제 */
	free(qp->tail);	/* 테일노드 삭제 */
	qp->head = qp->tail = NULL;	/* head, tail 포인터를 NULL로 초기화 */
}