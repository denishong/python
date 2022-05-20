#include <stdio.h>

int count = 0;
int arr_x[20];
int arr_y[20];
int top1 = 0, top2 = 0; 

void move(int n,int x,int y)
{
	printf("Line: %d n: %d x: %d y: %d \n",__LINE__, n, x, y);
	if (n > 1)
		move(n - 1, x, 6 - x - y);

	printf("Line: %d n: %d x: %d y: %d \n",__LINE__, n, x, y);
	count++;

	if (n > 1)
		move(n - 1, 6 - x - y, y);
	printf("Line: %d n: %d x: %d y: %d \n",__LINE__, n, x, y);
}

int main()
{
	int n;
	scanf("%d", &n);
	move(n,1,3);
	printf("%d\n", count);

	return 0;
}
