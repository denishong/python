#include <stdio.h>

int main(void)
{
    int num;

    printf("정수를 입력하세요: ");
    scanf("%d", num);

    printf("%d의 거듭제곱은 %d입니다.\n", num, num * num);

    return 0;
}
