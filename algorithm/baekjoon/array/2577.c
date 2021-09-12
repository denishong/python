#include <stdio.h>

int main()
{
    int A,B,C,i,digit=1,total; 
	int a=0,count[10]={0};
    scanf("%d %d %d", &A, &B, &C);

		total = A*B*C;
		while(total > 0)
		{
				a = total%10;
				count[a]++;
				total = total/10;
		}
		
		for(i=0; i<10; i++)
				printf("%d\n", count[i]);

	return 0;
}
