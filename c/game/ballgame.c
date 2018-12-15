#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>



typedef struct ball{
	int x;
	int y;
	int i;
	float j;
	int color;
	struct ball *next;
}BALL;
int i=0;
int k=0,stage=WHITE;
int DTIME=30;
int SIZE=10;
int t=0;
float bound=0.85;

struct bar{
	int x;
	int y;
	int i;
	int size;
}mybar={40,450,0,200};


BALL *head=NULL;
BALL **tail=&head;

void creatball();
int delball(BALL **);
void scankey();

void moveball(BALL**);
void moveball2(int,float,BALL*);
void movebar(int,float);

void drawball(BALL*);
void removeball(BALL*);

void checkball(BALL*);
void gameover();

void randmove(BALL*);
void randmove2(BALL*);
int boundball(BALL*,BALL*);
void alldel(BALL**,BALL***);
void option();

void main()
{
	int graphdrive = DETECT,graphmode;

	initgraph(&graphdrive,&graphmode,"");

	cleardevice();
	setactivepage(0);
	setvisualpage(0);
	settextstyle(0,0,8);

	creatball();
	while(1){
		rectangle(0,0,620,470);
		option();
		setfillstyle(1,15);
		bar(mybar.x,mybar.y,mybar.x+mybar.size-10,mybar.y+10);

		if(kbhit())
			scankey();

		if(head!=NULL){
			moveball(&head);
			drawball(head);
		}
		else gameover();

		delay(DTIME);

		setfillstyle(1,0);
		removeball(head);
		setfillstyle(1,0);
		bar(mybar.x-20,mybar.y,mybar.x+mybar.size+20,mybar.y+10);
		if(mybar.x>0&&mybar.x<615-mybar.size+10)
		mybar.x+=mybar.i;
	}

}
void creatball()
{

	(*tail)=(BALL*)malloc(sizeof(BALL));
	(*tail)->x=rand()%540+30;
	(*tail)->y=rand()%140+30;
	(*tail)->i=rand()%5-2;
	(*tail)->j=0;
	(*tail)->color=rand()%14+1;
	(*tail)->next=NULL;
	tail=&(*tail)->next;
}
int delball(BALL **dhead)
{
	BALL *temp=NULL;
	if((*dhead)==head&&(*dhead)->next==(*tail)){
		head=NULL;
		tail=(&head);
		return 1;
	}
	if((*dhead)->next==NULL){
		temp=(*dhead);
		(*dhead)=(*dhead)->next;
		free(temp);
		tail=dhead;
		return 1;
	}
	else{
		temp=(*dhead);
		(*dhead)=(*dhead)->next;
		free(temp);
		return 0;
	}
}

void drawball(BALL *head)
{
	if(i)
	head->color--;
	if(head->color<4)
	head->color=15;


	setfillstyle(1,head->color);
	bar(head->x-SIZE,head->y-SIZE,head->x+SIZE,head->y+SIZE);

	if(head->next!=NULL)
		drawball(head->next);
}
void removeball(BALL *head)
{
	bar(head->x-SIZE,head->y-SIZE,head->x+SIZE,head->y+SIZE);
	if(head->next!=NULL)
		removeball(head->next);
}

void moveball(BALL** dhead)
{


	((*dhead)->j)+=0.9;     //gravity


	if((*dhead)->y>mybar.y&&(*dhead)->y<mybar.y+50){  //ball to bar
		if((*dhead)->x>mybar.x&&(*dhead)->x<mybar.x+mybar.size/3){

			((*dhead)->j)*=(-bound);
			((*dhead)->y)+=(*dhead)->j;
			((*dhead)->i)-=10;
		}
		if((*dhead)->x>=mybar.x+(mybar.size/3)&&(*dhead)->x<mybar.x+(2*mybar.size/3)){
			(*dhead)->color--;
			((*dhead)->j)*=(-bound);
			((*dhead)->y)+=(*dhead)->j;
			k+=30;
		}
		if((*dhead)->x>=mybar.x+(2*mybar.size/3)&&(*dhead)->x<mybar.x+mybar.size){
			((*dhead)->j)*=(-bound);
			((*dhead)->y)+=(*dhead)->j;
			((*dhead)->i)+=10;
		}
	}

	if(((*dhead)->x)<10){            	//ball to well
		((*dhead)->i)*=(-0.8);
		((*dhead)->x)+=(*dhead)->i;
	}


	if((*dhead)->x>610){
	       ((*dhead)->i)*=(-0.8);
	       ((*dhead)->x)+=(*dhead)->i;
	}
	if(((*dhead)->y)>600){
		if(delball(dhead))
		return;

	}
	if((*dhead)->y<0){
	       ((*dhead)->j)*=(-0.8);
	       ((*dhead)->y)+=(*dhead)->j;
	}


	((*dhead)->x)+=((*dhead)->i);

	if(boundball(*dhead,head)){     		//ball to ball
	       ((*dhead)->i)*=(-0.9);
	       ((*dhead)->x)+=(*dhead)->i;
	}

	((*dhead)->y)+=((*dhead)->j);
	if(boundball((*dhead),head)){
	       ((*dhead)->j)*=(-0.9);
	       ((*dhead)->y)+=(*dhead)->j;
	}


	if((*dhead)->next!=NULL)
		moveball(&((*dhead)->next));
}
int boundball(BALL* dhead,BALL* head)
{
	if(dhead->color!=head->color)
		if(dhead->x>head->x-(SIZE+2)&&dhead->x<head->x+SIZE+2&&dhead->y>head->y-SIZE-2&&dhead->y<head->y+SIZE+2){
		       dhead->color--;
		       return 1;
		}

	if(head->next!=NULL)
		return boundball(dhead,head->next);
	else
		return 0;


}

void moveball2(int i,float j,BALL *head)
{
	(head->i)+=i;
	(head->j)+=j;
	if(head->next!=NULL)
		moveball2(i,j,head->next);
}

void scankey(){

	int input=0;
	input=getch();
	switch(input){
		case 't' : t=(t==1)?0:1;
			break;
		case '9' :
			setfillstyle(1,0);
			bar(50,50,600,300);
			outtextxy(50,50,"VICTORY!!");
			stage=0;
			SIZE=1;
			break;
		case 'z' : moveball2(-15,0,head);	//ball left
			break;
		case 'x' : moveball2(15,0,head);	//ball right
			break;
		case 75:if(mybar.x>0){
			mybar.i=-15;	//left
			mybar.x-=15;}
			break;
		case 77 : if(mybar.x<460){
			mybar.i=+15;
			mybar.x+=15;
			}       //right
			break;

		case '1' : i=(i==1)?0:1;
			break;
		case '2' : srand(clock());
			   creatball();
			break;
		case '3' : alldel(&head,&tail);
				creatball();
				break;
		case 32 : randmove(head);
			  randmove2(head);
			break;
		case 9  : randmove2(head);

			break;
		case '0' : closegraph();
				exit(0);

		default :break;

	}

}
void randmove(BALL *head)
{
	srand(clock());
	head->i=+rand()%20-10;
	//head->j=rand()%20-10;
	if(head->next!=NULL)
		randmove(head->next);

}
void randmove2(BALL *head)
{
	srand(clock());
	head->x=rand()%600;
	head->y=rand()%200;
	head->j=rand()%20-10;
	head->i=rand()%20-10;

	if(head->next!=NULL)
		randmove2(head->next);

}

void gameover()
{
	int input;
	settextstyle(0,0,5);
	bar(20,40,400,400);
	outtextxy(20,40,"GAME OVER!");
	outtextxy(20,80,"RE GAME?");
	outtextxy(20,120,"YES / NO");
	while(input!='y'&&input!='n'){
	input=getch();

	}

	switch(input){
		case 'y' :
			bound=0.85;
			stage=15;
			cleardevice();
			k=0;
			DTIME=30;
			SIZE=10;
			mybar.size=200;
			creatball();
			cleardevice();
			break;
		case 'n' :
			closegraph();
			exit(0);
		}

}

void alldel(BALL **head,BALL ***temp)//모든 자료 삭제 함수 정의
{
	BALL *ftemp;		//자료 삭제 정의 함수와 유사

	if((*head)->next==(**temp)){
		ftemp=(*head)->next;
		free((*head));
		(*head)=ftemp;
		(*temp)=head;

	}
	else{
		ftemp=(*head)->next;
		free((*head));
		(*head)=ftemp;
	}
		if((*head)!=NULL)	//자료가 남아있다면 다음자료 삭제
		alldel(head,temp);

}
void option()
{

	if(t)
	if(clock()%18==0)
	 creatball();

	if(stage==10||stage==5){
		if(clock()%9==0){
		creatball();
		k+=3;
		}
	}
	if(stage==0){
		if(clock()%2==0){
		creatball();
		k=0;
		}
	}


	if(clock()%2==0){
		setfillstyle(1,stage);
		bar(0,471,k,475);
		k+=3;
	}

	if(k>628)
	{
		if(bound<0.98);
		bound+=0.02;
		mybar.size-=10;
		stage--;
		setfillstyle(1,0);
		bar(50,50,600,300);
		bar(0,471,650,475);

		if(stage%2)
		SIZE--;
		if(stage==13||stage==9||stage==3)
		outtextxy(50,50,"DANGER!!");
		if(stage==6||stage==1)
		outtextxy(50,50,"DANGER!!");
		if(stage==10||stage==5){
		outtextxy(50,50,"BOUNS!!!");
		}
		if(stage==0){
		outtextxy(50,50,"HAPPY!");
		outtextxy(100,120,"BIRTH!!");
		outtextxy(150,190,"DAY!!");
		outtextxy(150,300,"2358");
		delay(2000);
		}
		k=0;
		creatball();
		setfillstyle(1,stage);
	}
	if(stage==13||stage==9||stage==3)
	{
		i=1;
		if(clock()%20==0)
		randmove(head);
		k+=3;
	}
	else i=0;
	if(stage==6||stage==1)
	{
		if(clock()%40==0)
		randmove2(head);


	}

}


