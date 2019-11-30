#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main()
{
    float num1, num2;

    printf("실수를 두 개 입력하세요: \n");
    scanf("%f %f", &num1, &num2);    // 값을 두 개 입력받아서 변수 두 개에 저장

    printf("%f %f\n", num1, num2);    // 변수의 내용을 출력

    return 0;
}
