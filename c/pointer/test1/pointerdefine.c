#include <stdio.h>

int main()
{
    int *numPtr;
    int num = 10;

    numPtr = &num;
    printf("%p\n", numPtr);
    printf("%p\n", &num);

    return 0;
}
