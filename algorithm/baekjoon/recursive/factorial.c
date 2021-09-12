#include <stdio.h>
int fac(int a)
{
	if(a > 0){
	return a*fac(a-1);
	}
	else
	return 1;

}

int main()
{
    int i,repeat;
	int fact=1; 
    scanf("%d", &repeat);


	printf("%d", fac(repeat));
    return 0;
}
