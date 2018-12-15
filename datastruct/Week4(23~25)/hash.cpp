#include "hash_chaining.h"
#include<stdio.h>
#include<stdlib.h>

/*--------------------------------------------------------------------------------------
Function name	: createHash() - 해시 생성 및 초기화 함수
Parameters		: hsp - 해시관리 구조체의 주소,  size - 해시 테이블의 사이즈
Returns			: 성공적으로 생성하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL createHash(CHash *hsp, int size)
{
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: hashFunction() - 해시값 계산 함수
Parameters		: hsp - 해시관리 구조체의 주소,  key - key값
Returns			: 해시값 리턴
--------------------------------------------------------------------------------------*/
int hashFunction(CHash *hsp, int key)
{
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: hashInput() - 해시에 데이터 삽입 함
Parameters		: hsp - 해시관리 구조체의 주소,  iData - 해시에 저장할 값
Returns			: 성공적으로 삽입하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL hashInput(CHash *hsp, int iData)
{
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: hashSearch() - 해시에서 데이터를 찾음
Parameters		: hp - 해시관리 구조체의 주소,  sData - 해시에 찾을 데이터 값
Returns			: 찾은 데이터의 해시 값, 못찾으면 -1 리턴
--------------------------------------------------------------------------------------*/
int hashSearch(CHash *hsp, int sData)
{
	
}

/*--------------------------------------------------------------------------------------
Function name	: hashDelete() - 해시에 데이터 삭제 함
Parameters		: hsp - 해시관리 구조체의 주소,  dData - 해시에서 삭제할 값
Returns			: 성공적으로 삭제하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL hashDelete(CHash *hsp, int dData)
{
	return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyHash() - 해시 소멸 함수
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyHash(CHash *hsp)
{
	return;
}

/*--------------------------------------------------------------------------------------
Function name	: hashPrint() - 해시에 저장된 데이터 출력 함수
Parameters		: hsp - 해시관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void hashPrint(CHash *hsp)
{
	int i;
	Node *np;
	if (hsp == NULL) {  /* hsp포인터 NULL check*/
		return;
	}
	printf("hash data : \n");
	for(i=0; i<hsp->size; i++){
		np = hsp->hash[i].next;
		printf("hash[%d] : ", i);
		while(np != NULL){
			printf("%5d", np->key);
			np= np->next;
		}
		printf("\n");
	}
	return;
}

