#include <stdio.h>
#include <stdlib.h>

char swap(char *str)
{
	char temp;
	temp = str[2];
	str[2] = str[0];
	str[0] = temp;

	//printf("%s\n", str);

	return (char *)str;
}

int main()
{

	int max=0;
	char A[4], B[4];
	int num_a, num_b;

	scanf("%s %s",A,B );

	swap( A);
	swap( B);

	num_a = atoi(A);
	num_b = atoi(B);

	if (num_a > num_b)
		max = num_a;
	else
		max = num_b;

	printf("%d\n", max);

	return 0;
}
