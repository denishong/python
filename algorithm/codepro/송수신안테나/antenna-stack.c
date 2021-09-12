#include <stdio.h>

int N =7 ;//송수신 안테나 수
int H[100000 + 10]= {2, 4, 3, 2, 2, 5, 1};//송수신 안테나 높이

int stk[1000000 + 10];
int sp;
void push(int h){
	stk[++sp] = h;
}
void pop(){
	sp--;
}
int top(){
	return stk[sp];
}
int empty(){
	return sp == 0;
}
void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &H[i]);
}
int Solve(){
	int totalcnt = 0;
	sp = 0;
	for (int i =0; i<N; i++){
		while( !empty() && ( top() < H[i])){
			totalcnt++;
			pop();
			printf("line %d sp : %d, i : %d\n", __LINE__, sp, i);
		}

		if ( !empty()){
			totalcnt++;
			printf("line %d sp : %d, i : %d\n", __LINE__, sp, i);
			if( top() == H[i]) pop();
			printf("line %d sp : %d, i : %d\n", __LINE__, sp, i);
		}

		push(H[i]);
		printf("H[%d] : %d \n", i, H[i]);
	}
	return totalcnt;
}

int main(){
	int ans = 0;
	//InputData();//	입력 함수

	//	코드를 작성하세요
	ans = Solve();
	printf("%d\n", ans);//출력 
	return 0;
}
