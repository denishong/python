#include <stdio.h>

int main()
{
    int* numPtr,* numPtr1;
    int num = 10;

    numPtr = &num;
    numPtr1 = &num;
    printf("%p\n", numPtr);
    printf("%p\n", numPtr1);
    printf("%p\n", &num);

    return 0;
}
