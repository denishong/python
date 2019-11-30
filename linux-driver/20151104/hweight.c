#if 0
#include <stdio.h>

unsigned int __sw_hweight32(unsigned int w)
{
	w -= (w >> 1) & 0x55555555;
	w =  (w & 0x33333333) + ((w >> 2) & 0x33333333);
	w =  (w + (w >> 4)) & 0x0f0f0f0f;
	return (w * 0x01010101) >> 24;
}

int main()
{
	int i;
	unsigned int count=0;
	unsigned int ch = 0x12345678; 
                     // 00010010001101000101011001111000	
	count = __sw_hweight32( ch );

	printf("count=%d\n", count );
	return 0;
}
#endif
#if 0
#include <stdio.h>

unsigned int __sw_hweight32(unsigned int w)
{
	w -= (w >> 1) & 0x55555555;
	w =  (w & 0x33333333) + ((w >> 2) & 0x33333333);
	w =  (w + (w >> 4)) & 0x0f0f0f0f;
	return (w * 0x01010101) >> 24;
}

int main()
{
	int i;
	unsigned int count=0;
	unsigned int ch = 0x12345678; 
                     // 00010010001101000101011001111000	
	count = __sw_hweight32( ch );

	printf("count=%d\n", count );
	return 0;
}
#endif
#if 0
#include <stdio.h>

/*
unsigned int __sw_hweight8(unsigned int w)
{
	unsigned int res = w - ((w >> 1) & 0x55);
	res = (res & 0x33) + ((res >> 2) & 0x33);
	return (res + (res >> 4)) & 0x0F;
}
*/

unsigned int __sw_hweight8(unsigned int w)
{
	unsigned int res = (w&0x55) + ((w >> 1) & 0x55);
	res = (res & 0x33) + ((res >> 2) & 0x33);
	return (res & 0xF) + ((res >> 4) & 0xf);
}

int main()
{
	int i;
	unsigned int count=0;
	unsigned int ch = 0x37; // 00110111
	
	count = __sw_hweight8( ch );

	printf("count=%d\n", count );
	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int i, count=0;
	unsigned char ch = 0x37; // 00110111

	for( i=0; i<8; i++ )
		if( ch & ( 1<<i ) )
			count++;

	printf("count=%d\n", count );
	return 0;
}
#endif
