#include <stdio.h>
int add(int a)
{
	if(a > 0)
	return (a+add(a-1));
	else
	return 0;

}

int main()
{
    int i,repeat;
	int fact=1; 
    scanf("%d", &repeat);


	printf("%d", add(repeat));
    return 0;
}
