#pragma once 
enum BOOL { FALSE, TRUE };

typedef struct _queue {
	int *queue;
	int size;
	int front, rear;
}Queue;

BOOL createQueue(Queue * qp, int size);		/* 큐 생성 및 초기화 함수 */
BOOL isQueueEmpty(const Queue *qp);			/* 큐가 완전히 비어있는가 */
BOOL isQueueFull(const Queue *qp);			/* 큐가 꽉차있는가 검사 */
BOOL enqueue(Queue * qp, int enqueData);	/* 큐에 데이터 하나를 저장 함 */
BOOL dequeue(Queue * qp, int * dequeData);	/* 큐에서 데이터 하나를 꺼냄 */
void printQueue(const Queue * qp);			/* 큐 내의 모든 데이터를 출력(dequeue하는 것은 아님) */
void destroyQueue(Queue * qp);				/* 큐 소멸 함수 */
