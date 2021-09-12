#include <stdio.h>

int N =7 ;//송수신 안테나 수
int H[100000 + 10]= {2, 4, 3, 2, 2, 5, 1};//송수신 안테나 높이

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &H[i]);
}

int main(){
	int ans = 0;
	//InputData();//	입력 함수

	//	코드를 작성하세요
	for(int i = 0; i < N-1; i++){
		int h = 0;
		for(int j = i+1; j < N; j++){
			if( h < H[j] ){
				ans++;
				h = H[j];
			printf("%d  %d \n", H[i], H[j]);
			}
			if(H[i] <= H[j])
				break;
		}
	}
	
	printf("%d\n", ans);//출력 
	return 0;
}
