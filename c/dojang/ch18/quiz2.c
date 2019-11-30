#include <stdio.h>

int main()
{
	int c1,c2,c3,c4;
	int avg;

	scanf("%d %d %d %d", &c1,&c2,&c3,&c4);

	if( (c1 >= 0) && (c1 <= 100) && \
		(c2 >= 0) && (c2 <= 100) && \
		(c3 >= 0) && (c3 <= 100) && \
		(c4 >= 0) && (c4 <= 100) ) 
	{
		avg = (c1 + c2 + c3 + c4)/4;
		if(avg >= 85)
			printf("합격\n");
		else
			printf("불합격\n");
	}
	else
	{
		printf("잘못된 점수\n");
	}
	
	return 0;
}
