#include <stdio.h>

void swap(int* a, int* b);
void aa(int* a, int* b);


int main(void) {
  int i = 300;
  int j = 500;

  int* ip = &i; // i의 주소(&i)를, 포인터 변수 ip 에 대입
  int* jp = &j; // j의 주소(&j)를, 포인터 변수 jp 에 대입


  printf("i = %d\n", i);
  printf("j = %d\n", j);
  // i = 300
  // j = 500


  // i, j의 주소가 들어 있는, 포인터 변수 ip, jp 를 입력
  swap(ip, jp);


  printf("i = %d\n", i);
  printf("j = %d\n", j);
  // i = 500
  // j = 300
  // 두 변수의 값이 교환되었습니다.
	aa(ip,jp);
  printf("i = %d\n", i);
  printf("j = %d\n", j);
  return 0;
}




void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
	printf("temp:%d *a : %d *b : %d \n", temp, *a, *b);
}
void aa(int* a, int* b) {
  *a = 100;
  *b = 20;
	printf("temp:%d *a : %d *b : %d \n", *a, *b);
}
