#include <stdio.h>

/*
1   666
2  1666
3  2666
4  3666
5  4666
6  5666
7  6660
8  6661
9  6662
10 6663
11 6664
12 6665
13 6666
14 6667
15 6668
16 6669
17 7666
18 8666
*/


int main(void) {
	int N,f=0,b,chk=0;
	int i,tmp,cnt=0;
	int nth = 0;
	
	scanf("%d", &N);

	for(i=1; i<=2700000;  i++)
	{
		cnt=0;

		tmp = i;
		while(tmp >0)
		{

			if(tmp%10 == 6)
			{
				cnt++;
			}else{
				cnt = 0;
			}

			tmp = tmp/10;

			if(cnt == 3)
			{
				nth++;
				if( N == nth )
				{
					printf("%d", i);
					break;
				}
			}
		}
	}

	return 0;
}
