#if 1
#include <stdio.h>

typedef int (*FP1)[2];
typedef FP1 (*FP2)(void);
typedef FP2 (*FP3)(void);
typedef	FP3 (*FP4)[2];
//-------------------------------
FP1 aaa(void)
{
	static int a[2][2];
	return a;
}

FP2 bbb(void)
{
	return aaa;
}

int main()
{
	FP3 p[2][2] = {{bbb,bbb},{bbb,bbb}};
	FP4 q = p;
	q[1][1]()()[1][1] = 10;
}
#endif
#if 0
#include <stdio.h>

int (*aaa(void))[2]
{
	static int a[2][2];
	return a;
}

int (*(*bbb(void))(void))[2]
{
	return aaa;
}

int main()
{
	int (*(*(*p[2][2])(void))(void))[2] = {{bbb,bbb},{bbb,bbb}};
	int (*(*(*(*q)[2])(void))(void))[2] = p;
	q[1][1]()()[1][1] = 10;
}
#endif

#if 0
#include <stdio.h>

typedef void (*FP1)(void);
//----------------------------
void aaa(void)
{
}

FP1 bbb(void)
{
	return aaa;
}

int main()
{
	bbb()();
}


#endif
#if 0
#include <stdio.h>

typedef void FP1(void);
typedef FP1* FP2;
//----------------------------
void aaa(void)
{
}

FP2 bbb(void)
{
	return aaa;
}

int main()
{
	bbb()();
}


#endif
#if 0
#include <stdio.h>

void aaa(void)
{
}

void (* bbb(void) )(void) 
{
	return aaa;
}

int main()
{
	bbb()();
}


#endif
#if 0
#include <stdio.h>
typedef int FP1[2];
typedef FP1* FP2;
//------------------------
FP2 foo(void) 
{
	static int a[2][2];
	return a;
}

int main()
{
	foo()[1][1] = 10;
}


#endif
#if 0
#include <stdio.h>
int (*foo(void))[2] 
{
	static int a[2][2];
	return a;
}

int main()
{
	foo()[1][1] = 10;
}

#endif
#if 0
#include <stdio.h>
void foo(void)
{
	printf("foo()\n");
}

int main()
{
	void (void) *p = foo;   // p = 0x40052d;
	return 0;
}
#endif
#if 0
#include <stdio.h>
void foo()
{
	printf("foo()\n");
}

int main()
{
	foo();
	return 0;
}
#endif
