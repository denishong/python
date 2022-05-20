#include <stdio.h>


int count = 0;
int arr_x[20];
int arr_y[20];
int top1 = 0, top2 = 0; 

void move(int n,int x,int y)
{
	if (n > 1)
		move(n - 1, x, 6 - x - y);
	arr_x[top1++] = x;
	arr_y[top2++] = y;
	count++;

	if (n > 1)
		move(n - 1, 6 - x - y, y);
}

int main()
{
	int n;
	scanf("%d", &n);
	move(n,1,3);
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d %d\n", arr_x[i], arr_y[i]);
	}

	return 0;
}
