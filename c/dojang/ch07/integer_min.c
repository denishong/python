#include <stdio.h>
#include <limits.h>

int main()
{
	char num1 = CHAR_MIN;
	char num11 = CHAR_MAX;
	short num2 = SHRT_MIN;
	short num22 = SHRT_MAX;
	int num3 = INT_MIN;
	int num33 = INT_MAX;
	long num4 = LONG_MIN;
	long num44 = LONG_MAX;
	long long num5 = LLONG_MIN;
	long long num55 = LLONG_MAX;

	printf("char minum value : %d,  char maximum value: %d\n", num1,num11); 
	printf("short minum value : %d, short maximum value :%d \n", num2,num22); 
	printf("interger minum value : %d, interger maximum value :%d \n", num3,num33); 
	printf("long minum value : %ld, long maximum value :%ld \n", num4,num44); 
	printf("long long minum value : %lld, long long maximum value :%lld \n", num5,num55); 

	return 0;
}
