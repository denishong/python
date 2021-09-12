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
	int N,f=0,b,chk=0;//f는 666앞의 수,b는 666뒤의 수,chk는 b 크기의 기준
	char c[5];
	
	scanf("%d", &N);

	if (N == 1) {
		printf("666");
		return 0;
	}

	while (N-- > 1) {
		if (chk == 0)
			b = 0;
		if (f % 10000 == 6666 && chk > 0) {//0000  9999까지
			b++;
			if (b == 10000) {
				chk = 0;
				f++;
			}
		}
		else if (f % 1000 == 666 && chk > 0) {//000  999까지
			b++;
			if (b == 1000) {
				chk = 0;
				f++;
			}
		}
		else if (f % 100 == 66 && chk>0) {//00부터 99까지
			b++;
			if (b == 100) {
				chk = 0;
				f++;
			}
		}
		else if (f % 10 == 6 && chk>0) {//0부터 9까지
			b++;
			if (b == 10) {
				chk = 0;
				f++;
			}
		}
		else {
			f++;
			chk++;
		}
	}

	if (f % 1000 == 666 && chk>0) {
		printf("%d%d", f, b);
	}
	else if (f % 100 == 66 && chk>0) {
		printf("%d6%d", f, b);
	}
	else if (f % 10 == 6 && chk>0) {
		printf("%d66%d", f, b);
	}
	else {
		printf("%d666", f);
	}
	


	return 0;
}
