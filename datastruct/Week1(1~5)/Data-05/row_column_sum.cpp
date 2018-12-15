#include <stdio.h>
#include <stdlib.h>

void initArray(int (*p)[4], int row);
void outputArray(int (*p)[4], int row);

int main()
{
	int  num[3][4];
	int row;
	row = sizeof(num)/sizeof(num[0]); // 행의 개수 구하기
	initArray(num, row);
	outputArray(num, row);

	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
void initArray(int (*p)[4], int row)
{
        // TODO
	return;
}
//---------------------------------------------------
void outputArray(int (*p)[4], int row)
{
	// TODO
	return;
}

