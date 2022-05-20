#include <stdio.h>

int recursion(int i)
{
	int total = 0;
	if (i > 10) return total;
	printf(" Recusion: %d \n", i);

	total = i+recursion(i+1);
	//printf(" Total : %d \n",total);
	printf(" i : %d \n",i);
}

int main()
{
	printf("result : %d \n", recursion(0) );
	return 0;
}
	
