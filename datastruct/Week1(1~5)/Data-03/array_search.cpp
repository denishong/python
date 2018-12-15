
#include <stdio.h>
#include <stdlib.h>
void printArray(int *ap, unsigned int cnt); // 배열내용 출력 함수
void initArray(int *ap, unsigned int size); // 1~20까지의 난수로 배열초기화하는 함수
int searchArray(int *ap, unsigned int size, int sData); // 검색함수

int main()
{
	int num[10];		// 데이터 저장 배열
	unsigned int size;  // 배열의 크기(방이 개수) 저장
	int sData;			// 검색할 데이터 저장
	int res=0;			// 검색 결과 저장
	int i;
	size = sizeof(num)/sizeof(num[0]);	// 배열 크기 계산

	initArray(num, size);
	printArray(num, size);

	for(i=0; i<5; i++){
		printf("# 검색할 정수를 입력하시오 : ");
		scanf("%d", &sData);
		res = searchArray(num, size, sData);
		if(res!=-1)
			printf("%d는 %d번 방에 있습니다.\n", sData, res);
		else
			printf("%d는 존재하지 않습니다.\n", sData);
	}
	getchar();
	getchar();
	return 0;
}
//---------------------------------------------------
int searchArray(int *ap, unsigned int size, int sData)
{
	// TODO

	return 0;
}
//---------------------------------------------------
void initArray(int *ap, unsigned int size)
{
	// TODO
}
//---------------------------------------------------
void printArray(int *ap, unsigned int cnt)
{
	// TODO
}

