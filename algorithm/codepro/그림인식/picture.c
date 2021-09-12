#include <stdio.h>

int N;//도화지 크기
char A[10 + 2][10 + 2];//도화지 색정보

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%s", A[i]);
}

void PrintData(){
	int i,j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			printf("%d", A[i][j]);
			}
		printf("\n");
}

int Solve(){

	int i, r, c, minr, minc, maxr,maxc, cnt = 0;
	int check[10] = {0};
	

	for(i = '1'; i <= '9'; i++){
		//i번씩 상하좌우 찾기
		minr = minc = 10;
		maxr = maxc = 0;

		for(r = 0; r < N; r++){
			for(c = 0; c < N; c++){
				if (A[r][c] != i) continue;
				if (minr > r) minr = r;
				if (maxr < r) maxr = r;
				if (minc > c) minc = c;
				if (maxc < c) maxc = c;
				}
			}
			printf("i : %c (minr, minc) (%d , %d) (maxr, maxc) (%d, %d)\n", i,minr, minc, maxr, maxc);
			if(minr == 10) continue; //해당색 없음
			//i번색 영역에 칠해진 다른 색 찾아 표시하기
			check[i-'0']++;
			for( r = minr; r <= maxr; r++){
				for( c = minc; c <= maxc; c++){
					if( A[r][c] == i) continue;
					check[A[r][c] - '0']++;
				}
			}
	}
		for( i = 1; i<= 9; i++){
			printf("check[%d] : %d \n", i, check[i]);
		}
	return cnt;
}

int main(){
	int ans = -1;
	InputData();//	입력 함수

	//	코드를 작성하세요
	ans = Solve();
	
	printf("%d\n", ans);//출력 
	return 0;
}

