#include <stdio.h>

int main()
{
	int i,n,temp;
	int a,b,c;

	scanf("%d", &n);

	for(i=100; i<=n; i++){

    a = i/100; 
    b = (i - a*100)/10; 
    c = (i - a*100 - b*10); 

	//printf("a: %d  b: %d c: %d  i: %d\n", a,b,c,i);
	temp = (a*101 + b*11 + 2*c);

	if(n == temp){
		printf("%d\n",(a*100 + 10*b +c) );
		break;
	}
	else if(i == n){
		printf("0\n");
	}


	}
	
	return 0;
}
