#include <stdio.h>

int main()
{
    int *numPtr = 10;
    int num = 10;

    printf("%p %d\n", numPtr, *numPtr);
    numPtr = &num;
    printf("%p %d\n", numPtr, *numPtr);
	
	*numPtr = 20;
    printf("%p %d\n", numPtr, *numPtr);
    printf("%p\n", &num);

    return 0;
}
