#include <stdio.h>
#define MAXN (int)1e4 

int N;
int D[MAXN+10]; 

int main(){
    int a;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d",&a);
        D[a]++;
    }

    for( int i=0; i<MAXN; i++){
        if(D[i]){ 
        for(int j=0; j<D[i]; j++)
            printf("%d\n",i);
        }
    }
    return 0;
}
