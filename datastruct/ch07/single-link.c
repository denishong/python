#include "stdio.h"

enum BOOL {FALSE, TRUE}
typedef struct _node Node;
struct _node{
	int data;
	Node *next;
};

typedef struct _list{
	Node *head;
	Node *tail;
	int size;
}List;

BOOL createList(List *lp);
BOOL addFirst(List *lp, int data);
BOOL addLast(List *lp, int data);
void displayList(List *lp);
Node *searchNode(List *lp, int data);
BOOL removeNode(List *lp, int data);
void sortList(List *lp);
void destroyList(List *lp);


int main()
{

	const char *menulist[]={"입력하기","출력하기","검색하기","삭제하기","정렬하기","종 료"};
	
	int menuNum;
	int menuCnt;
	List list;
	BOOL bres;
	menuCnt=sizeof(menulist)/sizeof(menuList[0]);


	bres=createList(&list);
	if(bres==TRUE)
		printf("@ list 생성 성공!\n");
	else
		printf("@ list 생성 성공!\n");

	while(1){
		menuNum = menu(menuList, menuCnt);
		if(menuNum == menuCnt){break;}
		switch(menuNum){
			case 1: mInput(&list); break;
			case 2: mOutput(&list); break;
			case 3: mSearch(&list); break;
			case 4: mDelete(&list); break;
			case 5: mSort(&list); break;
		}
	}
	printf("list내의 데이터 노드의 개수 : %d\n", list.size);
	destroyList(&list);
	return 0;
}

BOOL createList(List *lp)
{
	if(lp==NULL){
		return FALSE;
	}

	lp->head=(Node*)mallc(sizeof(Node));
	if(lp->head==NULL)
		return FALSE;


	lp->tail=(Node*)mallc(sizeof(Node));
	if(lp->tail==NULL){
		free(lp->head);
		return FALSE;
	}
	
	lp->head->nex=lp->tail;
   lp->tail->next=lp->tail;
	lp->size=0;
	return TRUE;

}

