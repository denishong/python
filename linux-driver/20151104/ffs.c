#if 1
#include <stdio.h>
unsigned long __ffs(unsigned long word)
{
	int num = 0;

	if ((word & 0xffffffff) == 0) {
		num += 32;
		word >>= 32;
	}
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

int main()
{
	unsigned long a = 0x0000000000000000UL;
	unsigned long num;
	if( a )
	{
		num = __ffs(a);
		printf("%lu\n", num );
	}
	else
		printf("세팅된 비트가 없습니다.\n" );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int a = 0x8000;

	int i;

	for( i=0; i<32; i++ )
		if( a & ( 1<<i ) )
			break;

	if( i<32 )
		printf("%d\n", i );
	return 0;
}
#endif
