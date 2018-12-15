#include "singlyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int createList(List *lp)
{
	if(lp==NULL){
      return FALSE;
   }   

   lp->head=(Node*)malloc(sizeof(Node));
   if(lp->head==NULL)
      return FALSE;


   lp->tail=(Node*)malloc(sizeof(Node));
   if(lp->tail==NULL){
      free(lp->head);
      return FALSE;
   }   
   
   lp->head->next=lp->tail;
   lp->tail->next=lp->tail;
   lp->size=0;

	return TRUE; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int addFirst(List *lp, int data)
{

	Node *newp;

   if(lp==NULL){
      return 0;
   }   

   newp=(Node*)malloc(sizeof(Node));
   if(newp!=NULL){
   newp->data=data;
   newp->next=lp->head->next;
   lp->head->next=newp;
   ++lp->size;
   return 1;
   }else{
   return 0;
   }

	return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int addLast(List *lp, int data)
{

	Node *newp;
   Node *btp;

   if(lp==NULL){
      return 0;
   }

   newp=(Node*)malloc(sizeof(Node));
   if(newp!=NULL){
   newp->data=data;
   newp->next=lp->tail;
   btp=lp->head;
   while(btp->next!=lp->tail){
      btp=btp->next;
   }

   btp->next=newp;
   ++lp->size;
   return 1;
   }else{
   return 0;
   }

	return 0; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	
	Node *curp;

   if(lp==NULL){
      return;
   }

   curp=lp->head->next;
   while(curp != lp->tail){
      printf("%8d\n", curp->data);
      curp=curp->next;
   }

   printf("\n");
   return;

}

/*----------------------------------------------------------------------------------
Function name	: searchNode - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int removeNode(List *lp, int data)
{
	// TODO

	return 0; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	// TODO

	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	// TODO

	return;
}

