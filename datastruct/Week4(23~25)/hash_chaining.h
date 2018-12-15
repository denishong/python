#ifndef HASH_CHAINING_H_
#define HASH_CHAINING_H_

#define FALSE (0)
#define TRUE (1)
#define HASH_SIZE (10) /* 해시 테이블의 size */

typedef int BOOL;

typedef struct _node{
	int key;
	struct _node *next;
}Node;

typedef struct _chaining_hash {
	Node *hash;   /* Node형태로 저장되는 해시테이블 */
	int size;     /* hash table크기 (bucket 크기) */
	int dataCnt;  /* hash table내의 데이터의 개수 */
}CHash;

BOOL createHash(CHash *hp, int size);		/* 해시 생성 및 초기화 함수 */
int hashFunction(CHash *hp, int key);		/* 해시값 계산 함수 */
BOOL hashInput(CHash *hp, int iData);	    /* 해시에 데이터 삽입 함 */
int hashSearch(CHash *hp, int sData);	    /* 해시에서 데이터를 찾음 */
BOOL hashDelete(CHash *hp, int dData);	    /* 해시에 데이터 삭제 함 */
void destroyHash(CHash *hp);				/* 해시 소멸 함수 */
void hashPrint(CHash *hp);                  /* 테스트용 함수 - 해시 테이블의 내용 출력 */

#endif /* HASH_CHAINING_H_ */
