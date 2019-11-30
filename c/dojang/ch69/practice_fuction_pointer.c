#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
} 

int mul(int a, int b)
{
    return a * b;
} 

int div(int a, int b)
{
    return a / b;
}


struct Calc {
	int (*fp[4])(int, int);
};

int excuter( int (*fp)(int, int), int a, int b)
{
	return fp(a,b);
}

int (*getFunc(struct Calc *c, int index))(int, int)
{
	return c->fp[index];
}

int main()
{
	 struct Calc c = {{add,sub,mul,div}};


    printf("%d\n", excuter(getFunc(&c, 0), 10, 20)); 
    printf("%d\n", excuter(getFunc(&c, 1), 10, 20)); 

    return 0;
}
