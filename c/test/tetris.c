#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>				  //사운드_관련_헤더 
#pragma comment(lib,"winmm.lib")   //사운드_관련(라이브러리_읽어들임) <-> 프로젝트 설정->'라이브러리 참조'로도 가능
#include <process.h>

//방향키
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

//맵_크기
#define map_x 17
#define map_y 20
#define map_x_move 2
#define map_y_move 3
#define map_save_num 6

//전역_변수
static int map_feild[map_y][map_x];
static int remove_map_feild[map_y][map_x];
bool game_runtime=TRUE;
int model_selcet_1=0, model_selcet_2=0, model_transform=0, x=0, y=1;
bool model_select_ok=FALSE, convert_on=FALSE;
bool y_comdown=FALSE;
int key_input1=0, key_input2=0, key_input3=0, key_input4=0, model_control=0;
int model_x_[map_save_num], model_y_[map_save_num];
int curtime=0, count=0;
bool player_interrupt=FALSE;
int CLOCK_PER_SEC=1000;


//enum
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

//함수_전방선언
void print_test_num(void);
void game_init();
void map_frame_draw(void);
void event_key_input(void);
void block_draw(void);
void block_delete(void);
void select_model(void);
void block_init(void);
void block_0(void);
void block_1(void);
void block_2(void);
void block_3(void);
void block_convert(void);
void block_line_delete(void);
void block_line_remove(int Clear_limit);
void block_down(void);
void block_3_redraw(void);
bool block_transform(int model_control_num);
bool block_crush_L(int model_control_num);
bool block_crush_R(int model_control_num);
bool block_crush_D(int model_control_num);

//---------------------------------------
void setcolor(int color, int bgcolor = 0);
void gotoxy(int x,int y);
void setcursortype(CURSOR_TYPE c);


//본문------------------------------------------
int main(void)
{
	//초기화 및 맵을 그린다.
	game_init();
	map_frame_draw();
	
	//게임이 실행 되는 중
	while(game_runtime)
	{
		//시간제어
		int time=double(clock())/CLOCK_PER_SEC;
		if (curtime<time && !player_interrupt)
		{
			curtime=time;
			block_down();
		}
		event_key_input();
		select_model();
		block_delete();

		//빈 공간을 한번 출력함으로써 부분적으로 삭제한다.
		gotoxy(95,8);
		printf("                   ",time);

		gotoxy(95,8);
		printf("Time : %d\n",time);

		//모델을 선택한다.
		switch(model_selcet_1)
		{
		case 0:
			block_0();
			break;
		case 1:
			block_1();
			break;
		case 2:
			block_2();
			break;
		case 3:
			block_3();
			break;
		}
		//선택한 모델을 그린다.
		block_draw();
	}
	return 0;
}

//함수_선언(제작)------------------------------------------
//테스트를 위한 함수
void print_test_num(void)
{
	gotoxy(55,2);
	printf("model_selcet_1 : %d",model_selcet_1);
	gotoxy(55,3);
	printf("model_selcet_2 : %d",model_selcet_2);

	int i=0;
	//지움
	gotoxy(95,2);
	printf("            ");
	gotoxy(95,3);
	printf("            ");
	//그림
	setcolor(2);
	gotoxy(95,2);
	printf("순수: X= %d", x);
	setcolor(2);
	gotoxy(95,3);
	printf("순수: Y= %d", y);
	//지움
	for (i=0; i<map_save_num; i++)
	{	
		gotoxy(95,4);
		printf("        ");
		gotoxy(95,5);
		printf("        ");

		gotoxy(95,6);
		printf("        ");
		gotoxy(95,7);
		printf("        ");
	}
	//그림
	for (i=0; i<map_save_num; i++)
	{	
		setcolor(2);
		gotoxy(95,4);
		printf("x=%d번 ", i);
		gotoxy(95,5);
		printf("=   %d",model_x_[i]);

		gotoxy(95,6);
		printf("y=%d번 ", i);
		gotoxy(95,7);
		printf("=   %d",model_y_[i]);
	}
}
//사용자 입력 함수
void event_key_input(void)
{
	int evnet_key;
	//kbhit()는 키가 눌렸는지 안눌렸는지 알려준다.
	if (kbhit())
	{
		print_test_num();
		//getch()는 어떤 키가 눌렸는지 알려준다.
		evnet_key=getch();
		switch(evnet_key)
		{
		case LEFT:
			if (!block_crush_L(model_control))
			{
				x--;
			}
			break;

		case RIGHT:
			if (!block_crush_R(model_control))
			{
				x++;
			}
			break;

		case UP:
			if (!block_transform(model_control))
			{
				model_transform++;
			}
			break;

		case DOWN:
			player_interrupt=TRUE;
			if (!y_comdown)
			{
				block_down();
			}
			break;

		case SPACE:
			player_interrupt=TRUE;
			if (!y_comdown)
			{
				block_down();
			}
			break;

		case ESC:
			game_runtime=FALSE;
			break;
		}
	}else
	{
		player_interrupt=FALSE;
	}
}

//블럭을 한칸 내린다.
void block_down(void)
{
	//블럭을 변환하는 변환 값이 없으면
	if (!convert_on)
	{
		//충돌체크를 하고, 이상이 없으면 y를 내린다.
		if (!block_crush_D(model_control))
		{
			y_comdown=TRUE;
			y++;
		}
	}else
	{
		//충돌이 되었으면 삭제, 블럭 초기화.
		block_line_delete();
		block_init();
	}
	y_comdown=FALSE;
}
//블럭 라인삭제
void block_line_delete(void)
{
	int i, j;
	bool remove_on=FALSE;
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 3)
			{
				count++;
			}
		}
		if (count==map_x-2) //양쪽 벽 제외
		{
			for(i=0; i<map_x; i++)
			{
				if (map_feild[j][i] == 3)
				{
					map_feild[j][i]=0;
					remove_on=TRUE;
				}
			}
			if (remove_on)
			{
				block_line_remove(j);
				remove_on=FALSE;
			}
		}
		count=0;
		i=0;
	}
	j=0;
}
//삭제 된 위의 블럭 라인 이동
void block_line_remove(int Clear_limit)
{
	int i,j;
	//copy
	for (j=0; j<Clear_limit; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 3)
			{
				remove_map_feild[j][i]=map_feild[j][i];
			}
		}
		i=0;
	}
	//clear
	for (j=0; j<Clear_limit; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 3)
			{
				map_feild[j][i]=0;
			}
		}
		i=0;
	}
	//paste
	for (j=0; j<Clear_limit; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (remove_map_feild[j][i] == 3)
			{
				map_feild[j+1][i]=remove_map_feild[j][i];
			}
		}
		i=0;
	}
	//clear
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			remove_map_feild[j][i]=0;
		}
		i=0;
	}
}
//블럭 초기화
void block_init(void)
{
	model_control=0;
	key_input1=0;
	key_input2=0;
	key_input3=0;
	key_input4=0;
	x=map_x/2;
	y=1;
	model_transform=0;
	model_select_ok=FALSE;
	convert_on=FALSE;
	block_draw();
	block_3_redraw();
}
//블럭 왼쪽 충돌 체크
bool block_crush_L(int model_control_num)
{
	int i;
	for (i=0; i<=model_control_num; i++)
	{
		if (map_feild[model_y_[i]][model_x_[i]-1]==1 || map_feild[model_y_[i]][model_x_[i]-1]==3)
		{
			return TRUE;
		}
	}
	return FALSE;
}
//블럭 오른쪽 충돌 체크
bool block_crush_R(int model_control_num)
{
	int i;
	for (i=0; i<=model_control_num; i++)
	{
		if (map_feild[model_y_[i]][model_x_[i]+1]==1 || map_feild[model_y_[i]][model_x_[i]+1]==3)
		{
			return TRUE;
		}
	}
	return FALSE;
}
//블럭 아래 충돌 체크
bool block_crush_D(int model_control_num)
{
	int i;
	for (i=0; i<=model_control_num; i++)
	{
		if (map_feild[model_y_[i]+1][model_x_[i]]==1 || map_feild[model_y_[i]+1][model_x_[i]]==3)
		{
			convert_on=TRUE;
			block_convert();
			return TRUE;
		}
	}
	return FALSE;
}
//블럭을 변환한다 (이동 불가의 쌓인 블럭으로)
void block_convert(void)
{
	int i, j;
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 2)
			{
				map_feild[j][i]=3;
			}
		}
		i=0;
	}
	j=0;
	block_3_redraw();
}
//움직일 수 있는 블럭 =2 , 쌓인 블럭 =3 
//3번 블럭, 즉 쌓인 블럭을 다시 그린다는 의미.
void block_3_redraw(void)
{
	int i, j;
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if  (map_feild[j][i] == 3)
			{
				gotoxy(i*2+map_x_move,j+map_y_move);
				setcolor(14);
				puts("■");
			}
		}
		i=0;
	}
	j=0;
}
//2번 블럭을 삭제한다.
void block_delete(void)
{
	int i, j;
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 2)
			{
				map_feild[j][i] =0;
			}
		}
		i=0;
	}
	j=0;
}
//0번 블럭 선택.
void block_0(void)
{
	if (!convert_on)
	{
		if (model_transform>1)
		{
			model_transform=0;
		}
		switch (model_transform)
		{
		case 0:
			key_input1=0; //기본
			key_input2=0; //기본
			break;
		case 1:
			key_input1=1; //변형
			key_input2=-2; //변형
			break;
		}
		map_feild[y+key_input1][x-1]=2;	
		map_feild[y][x]=2;				
		map_feild[y+1][x]=2;		                
		map_feild[y+1+key_input1][x+1+key_input2]=2;	

		model_x_[0]=x-1;
		model_y_[0]=y+key_input1;
		model_x_[1]=x;
		model_y_[1]=y;
		model_x_[2]=x;
		model_y_[2]=y+1;
		model_x_[3]=x+1+key_input2;
		model_y_[3]=y+1+key_input1;

		model_control=3;
	}
}

void block_1(void)
{
	if (!convert_on)
	{
		if (model_transform>1)
		{
			model_transform=0;
		}
		switch (model_transform)
		{
		case 0:
			key_input1=0; //기본
			key_input2=0; //기본
			key_input3=0; //기본
			key_input4=0; //기본
			break;
		case 1:
			key_input1=-1; //변형
			key_input2=-2; //변형
			key_input3=1;  //변형
			key_input4=2;  //변형
			break;
		}

		map_feild[y+key_input4][x-2+key_input4]=2;	//0,6
		map_feild[y+key_input3][x-1+key_input3]=2;	//0,7
		map_feild[y][x]=2;			        //0,8
		map_feild[y+key_input1][x+1+key_input1]=2;	//0,9
		map_feild[y+key_input2][x+2+key_input2]=2;	//0,10

		model_x_[0]=x-2+key_input4;
		model_y_[0]=y+key_input4;
		model_x_[1]=x-1+key_input3;
		model_y_[1]=y+key_input3;
		model_x_[2]=x;
		model_y_[2]=y;
		model_x_[3]=x+1+key_input1;
		model_y_[3]=y+key_input1;
		model_x_[4]=x+2+key_input2;
		model_y_[4]=y+key_input2;

		model_control=4;
	}
}

void block_2(void)
{
	if (!convert_on)
	{
		map_feild[y][x]=2;				//0,8
		map_feild[y][x+1]=2;				//0,9
		map_feild[y+1][x]=2;				//1,8
		map_feild[y+1][x+1]=2;				//1,9

		model_x_[0]=x;
		model_y_[0]=y+1;
		model_x_[1]=x+1;
		model_y_[1]=y+1;

		model_control=1;
	}
}

void block_3(void)
{
	if (!convert_on)
	{
		if (model_transform>3)
		{
			model_transform=0;
		}
		switch (model_transform)
		{
		case 0:
			map_feild[y][x]=2;			//0,8
			map_feild[y][x+1]=2;			//0,9
			map_feild[y+1][x+1]=2;			//1,9
			map_feild[y+2][x+1]=2;			//2,9

			model_x_[0]=x;
			model_y_[0]=y;
			model_x_[1]=x+1;
			model_y_[1]=y+2;

			model_control=1;
			break;
		case 1:
			map_feild[y+1][x+2]=2;			//1,10
			map_feild[y+2][x]=2;			//2,8
			map_feild[y+2][x+1]=2;		   	//2,9
			map_feild[y+2][x+2]=2;			//2,10

			model_x_[0]=x;
			model_y_[0]=y+2;
			model_x_[1]=x+1;
			model_y_[1]=y+2;
			model_x_[2]=x+2;
			model_y_[2]=y+2;

			model_control=2;
			break;
		case 2:
			map_feild[y][x+1]=2;			//0,9
			map_feild[y+1][x+1]=2;			//1,9
			map_feild[y+2][x+1]=2;			//2,9
			map_feild[y+2][x+2]=2;		    	//2,10

			model_x_[0]=x+1;
			model_y_[0]=y+2;
			model_x_[1]=x+2;
			model_y_[1]=y+2;

			model_control=1;
			break;
		case 3:
			map_feild[y+2][x]=2;			//2,8
			map_feild[y+2][x+1]=2;			//2,9
			map_feild[y+2][x+2]=2;			//2,10
			map_feild[y+3][x]=2;			//3,8

			model_x_[0]=x+1;
			model_y_[0]=y+2;
			model_x_[1]=x+2;
			model_y_[1]=y+2;
			model_x_[2]=x;
			model_y_[2]=y+3;

			model_control=2;
			break;
		}
	}
}
//블럭 모양 변경
bool block_transform(int model_control_num)
{
	int i;
	int _key_input1, _key_input2, _key_input3, _key_input4;
	int _model_x_[6], _model_y_[6];
	int _model_transform, _model_control;

	_model_control=model_control_num;
	_model_transform=model_transform;
	_model_transform++;

	//블록별로 지정이 필요함. 
	//해당 스위치문만 유동적
	switch(model_selcet_1)
	{
	case 0:
		if (_model_transform>1)
		{
			_model_transform=0;
		}

		switch (_model_transform)
		{
		case 0:
			_key_input1=0; //기본
			_key_input2=0; //기본
			break;
		case 1:
			_key_input1=1; //변형
			_key_input2=-2; //변형
			break;
		}

		_model_x_[0]=x-1;
		_model_y_[0]=y+_key_input1;
		_model_x_[1]=x;
		_model_y_[1]=y;
		_model_x_[2]=x;
		_model_y_[2]=y+1;
		_model_x_[3]=x+1+_key_input2;
		_model_y_[3]=y+1+_key_input1;
		break;

	case 1:
		if (_model_transform>1)
		{
			_model_transform=0;
		}

		switch (_model_transform)
		{
		case 0:
			_key_input1=0; //기본
			_key_input2=0; //기본
			_key_input3=0; //기본
			_key_input4=0; //기본
			break;
		case 1:
			_key_input1=-1; //변형
			_key_input2=-2; //변형
			_key_input3=1;  //변형
			_key_input4=2;  //변형
			break;
		}

		_model_x_[0]=x-2+_key_input4;
		_model_y_[0]=y+_key_input4;
		_model_x_[1]=x-1+_key_input3;
		_model_y_[1]=y+_key_input3;
		_model_x_[2]=x;
		_model_y_[2]=y;
		_model_x_[3]=x+1+_key_input1;
		_model_y_[3]=y+_key_input1;
		_model_x_[4]=x+2+_key_input2;
		_model_y_[4]=y+_key_input2;
		break;

	case 2:
		_model_x_[0]=x;
		_model_y_[0]=y+1;
		_model_x_[1]=x+1;
		_model_y_[1]=y+1;
		break;

	case 3:
		if (_model_transform>3)
		{
			_model_transform=0;
		}

		switch (_model_transform)
		{
		case 0:
			_model_x_[0]=x;
			_model_y_[0]=y;
			_model_x_[1]=x+1;
			_model_y_[1]=y+2;
			_model_control=1;
			break;
		case 1:
			_model_x_[0]=x;
			_model_y_[0]=y+2;
			_model_x_[1]=x+1;
			_model_y_[1]=y+2;
			_model_x_[2]=x+2;
			_model_y_[2]=y+2;
			_model_control=2;
			break;
		case 2:
			_model_x_[0]=x+1;
			_model_y_[0]=y+2;
			_model_x_[1]=x+2;
			_model_y_[1]=y+2;
			_model_control=1;
			break;
		case 3:
			_model_x_[0]=x+1;
			_model_y_[0]=y+2;
			_model_x_[1]=x+2;
			_model_y_[1]=y+2;
			_model_x_[2]=x;
			_model_y_[2]=y+3;
			_model_control=2;
			break;
		}
		break;
	}

	for (i=0; i<=_model_control; i++)
	{
		if (map_feild[_model_y_[i]][_model_x_[i]]==1 || map_feild[_model_y_[i]][_model_x_[i]]==3)
		{
			return TRUE;
		}
	}
	return FALSE;
}
//블럭을 그린다.
void block_draw(void)
{
	int i, j;
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 0)
			{
				gotoxy(i*2+map_x_move,j+map_y_move);
				setcolor(15);
				puts("  ");
			}
			if (map_feild[j][i] == 2)
			{
				gotoxy(i*2+map_x_move,j+map_y_move);
				setcolor(15);
				puts("■");
			}
		}
		i=0;
	}
	j=0;
}
//맵을 그린다.
void map_frame_draw(void)
{
	int i, j;
	for (j=0; j<map_y; j++)
	{
		for(i=0; i<map_x; i++)
		{
			if (map_feild[j][i] == 1)
			{
				gotoxy(i*2+map_x_move,j+map_y_move);
				setcolor(8);
				puts("▣");
			}else if  (map_feild[j][i] == 0)
			{
				gotoxy(i*2+map_x_move,j+map_y_move);
				puts("  ");
			}
		}
		i=0;
		printf("\n");
	}
	j=0;
}
//게임 전체 초기화
void game_init()
{
	//system("mode con: cols=76 lines=24");
	system("mode con: cols=148 lines=28");
	setcursortype(NOCURSOR);
	srand(time(NULL));
	model_selcet_2=rand()%4;
	int i, j;

	for (i=0; i<map_save_num; i++)
	{	
		model_x_[i]=0;
		model_y_[i]=0;
	}

	for (j=0; j<map_y; j++)
	{
		for (i=0; i<map_x; i++)
		{
			if ( i == 0 || i == map_x-1 )
			{
				map_feild[j][i]=1;
			}else 	if ( j == 0 || j == map_y-1 )
			{
				map_feild[j][i]=1;
			}
		}
		i=0;
	}
	print_test_num();
}
//모델 선택
void select_model(void)
{
	if (!model_select_ok)
	{
		model_selcet_1=model_selcet_2;
		model_selcet_2=rand()%4;
		block_init();
		model_select_ok=TRUE;
	}
}

//기본_필요_함수------------------------------------------------------------------
void setcolor(int color, int bgcolor) //글자색상
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void gotoxy(int x,int y) //커서이동
{	
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

void setcursortype(CURSOR_TYPE c) //커서제거(타입)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize=1;
		CurInfo.bVisible=FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize=100;
		CurInfo.bVisible=TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize=20;
		CurInfo.bVisible=TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

