#include <stdio.h>

int CalcDoubleArrayLen(double array[])
{
     return sizeof(array)/sizeof(double);
}

int main(void)
{
     double array[8];

     printf("%d", sizeof(array) + CalcDoubleArrayLen(array));

     return 0;
}
