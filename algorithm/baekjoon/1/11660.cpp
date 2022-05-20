#include <iostream>
using namespace std;
int A[1030][1030];

int main(){
    int N,M;
    int x1,x2,y1,y2;
    
    cin>>N>>M; 
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>A[i][j];
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            A[i][j] += A[i-1][j];
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            A[i][j] += A[i][j-1];
    
    for(int i=0;i<M;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        printf("%d\n",A[x2][y2]-A[x1-1][y2]-A[x2][y1-1]+A[x1-1][y1-1]);
    }
    
    return 0;
}
