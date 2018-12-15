#include <stdio.h>


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

int createList(List *lp);
int addFirst(List *lp, int data);
int addLast(List *lp, int data);
void displayList(List *lp);
Node *searchNode(List *lp, int data);
int removeNode(List *lp, int data);
void sortList(List *lp);
void destroyList(List *lp);


int main()
{

	const char *menulist[]={"입력하기","출력하기","검색하기","삭제하기","정렬하기","종 료"};
	
	int menuNum;
	int menuCnt;
	List list;
	int bres;
	menuCnt=sizeof(menulist)/sizeof(menulist[0]);


	bres=createList(&list);
	if(bres==1)
		printf("@ list 생성 성공!\n");
	else
		printf("@ list 생성 성공!\n");

	while(1){
		menuNum = menu(menulist, menuCnt);
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

int createList(List *lp)
{
	if(lp==NULL){
		return 0;
	}

	lp->head=(Node*)mallc(sizeof(Node));
	if(lp->head==NULL)
		return 0;


	lp->tail=(Node*)mallc(sizeof(Node));
	if(lp->tail==NULL){
		free(lp->head);
		return 0;
	}
	
	lp->head->next=lp->tail;
   lp->tail->next=lp->tail;
	lp->size=0;
	return 1;

}

int addFirst(List *lp, int data)
{
	Node *newp;

	if(lp==NULL){
		return 0;
	}

	newp=(Node*)mallc(sizeof(Node));
	if(newp!=NULL){
	newp->data=data;	
	newp->next=lp->head->next;
   lp->head->next=newp;
	++lp->size;
	return 1;
	}else{
	return 0;
	}

}

int addLast(List *lp, int data)
{
	Node *newp;
	Node *btp;

	if(lp==NULL){
		return 0;
	}

	newp=(Node*)mallc(sizeof(Node));
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

}

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
