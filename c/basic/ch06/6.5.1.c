#include <stdio.h>
int main()
{
	int a;
	int sum=0;

	for(a=1;a<=10;a++){
		printf("%d",a);
		sum+=a;
	}
	printf("\n sum=%d", sum);
	return 0;
}
