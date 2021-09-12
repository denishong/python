#include <stdio.h>

void f(int (*p)[4], int nSize)
{
 for(int i = 0; i < nSize; i++)
  for(int j = 0; j < 4; j++)
   printf("p = %d\n", p[i][j]);
}

void f(int (*p)[4])
{
 for(int i = 0; i < 3; i++)
  for(int j = 0; j < 4; j++)
   printf("p = %d\n", p[i][j]);
}

int test(int n, float f)
{
 printf("%d, %f\n", n, f);

 return n * 2;
}

int (*func2(int n1, int n2))(int, float)
{
 printf("n1(%d) + n2(%d) = %d\n",n1, n2, n1 + n2);

 return test;
}

typedef int (*F)(int, float);
F func(int (*p)(int, float), int n, float f)
{
 p(n, f);

 return test;
}

int main()
{
 int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
 int b[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
 int c[3][3][3] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
 
 //int *p = a;
 int (*pFunc)(int, float) = test;

 func(test, 10, 10.1f)(11, 11.1f);
 test(12, 12.1f);
 func2(1, 2)(13, 13.1f);
 pFunc(14, 14.1f);

 void *p = a;
 void *p2 = c;
 
 b[0] = 0;
 1[b] = 1;

 for(int i = 0; i < sizeof b / sizeof(int); i++)
  printf("b[%d] = %d\n",i, b[i]);

 for(int i = 0; i < 3; i++)
  printf("a = %d, b = %d, c = %d, p(int*) = %d, p(int(*)[4]) = %d, p2(int(*)[3][3]) = %d\n", **(a+i), *(b+i), ***(c+i), *((int*)p+i), **((int(*)[4])p+i), ***((int(*)[3][3])p2+i));

 int (*ptr)[3][3] = c;
 for(int i = 0; i < 3; i++)
  for(int j = 0; j < 3; j++)
   for(int k = 0; k < 3; k++)
    printf("c = %d\n", ptr[i][j][k]);

 printf("c = %x\n", c);
 printf("c[0] = %x\n", c[0]);
 printf("c[0][0] = %x\n", c[0][0]);
 printf("&c[0][0][0] = %x\n", &c[0][0][0]);
 printf("test = %x\n", test);

 printf("sizeof(c) = %d\n", sizeof(c));
 printf("sizeof(c[0]) = %d\n", sizeof(c[0]));
 printf("sizeof(c[0][0]) = %d\n", sizeof(c[0][0]));
 printf("sizeof(c[0][0][0]) = %d\n", sizeof(c[0][0][0]));

 f(a, sizeof(a) / sizeof(a[0]));
 f(a);

 return 0;
}
