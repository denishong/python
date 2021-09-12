#include <stdio.h>

int main()
{
    int input[10]={0}, remain[10]={0}; 
	int check[42]={0};
	int i,count=0;

	for(i=0; i<10; i++)
	    scanf("%d", &input[i]);

	for(i=0; i<10; i++)
		remain[i] = input[i]%42;

	for(i=0; i<10; i++)
		check[remain[i]]++;
	
	for(i=0; i<42; i++)
	{
		if(check[i] != 0)
			count++;
	}
		printf("%d\n", count);
	return 0;
}
