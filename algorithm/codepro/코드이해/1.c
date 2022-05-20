#include <stdio.h>

int N;
int A[30 + 10];
int sol[30 + 10];

void InputData(void){
	int i;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
}
void Solve(void){
	int value, cnt=0, from=0;
	printf("%d\n",N);
	value = A[from];
	while( cnt < N){
        while(value == 0){
     		printf( "from : %d, line : %d \n" ,   from ,__LINE__);
            from = (from +2) %N;
            value = A[from];
        }		
     printf("%d ", value);
     cnt++;
     A[from] = 0;
     printf( "from : %d, line : %d \n" ,   from ,__LINE__);
     from = (value + from) % N;
     //printf( "value : %d from : %d, line : %d \n" ,  value, from ,__LINE__);
     value = A[from];
	}
}
void OutputData(void){
	int i;
	printf("%d\n", N);
	for(i=0;i<N;i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}

int main(void){
	InputData();
	Solve();
	return 0;
}
