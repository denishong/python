#include <stdio.h>

int main()
{
	int i,n,temp;
	int a,b,c;

	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		temp = i + i%10 + (i%100)/10 + (i%1000)/100 + (i%10000)/1000 + (i%100000)/10000\
		        + (i%1000000)/100000 + (i%10000000)/1000000;
		//printf("i: %d  temp : %d \n", i, temp);

		if(n == temp)
		{
			printf("%d\n",i);
			break;
		}
		else if(i == n)
		{
			printf("0\n");
		}
	}
	
	return 0;
}
