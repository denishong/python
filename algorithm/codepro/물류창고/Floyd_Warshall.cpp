#include <iostream>
using namespace std;

int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D
#define IMP (100*100 +10)
#define MAXN 110
int dist[MAXN][MAXN];

void InputData(){
    int i;
    cin >> N >> M;
    for (i = 0; i < M; i++){
        cin >> A[i] >> B[i] >> D[i];
    }
}
void Solve(){
    int ans = IMP;
    int max;
    for(int s=1; s<=N; s++){
        for(int e=1; e<=N; e++){
            if( s!=e) dist[s][e]=IMP;
            else dist[s][e]=0;
        }
    }
    for(int i=0; i<M; i++) dist[A[i]][B[i]] = dist[B[i]][A[i]] = D[i];
	
    for(int s=1; s<=N; s++){
        for(int e=1; e<=N; e++){
           cout << dist[s][e] << ' ';
        }
        cout << endl;
    }

    for(int k=1; k<=N; k++){
        for(int s=1; s<=N; s++){
            for(int e=1; e<=N; e++){
    cout << "k,s,e:" << k << ' ' << s << ' ' << e ;
    cout << "dist[s][e]:" << dist[s][e] << ' ';
    cout << "dist[s][k]:" << dist[s][k] << ' ';
    cout << "dist[k][e]:" << dist[k][e];
                if(dist[s][e] > dist[s][k] + dist[k][e]){
    cout << "distance update" << endl;
                    dist[s][e] = dist[s][k] + dist[k][e];
                }
    cout << endl;
            }
        }
    }
	
    for(int s=1; s<=N; s++){
        max = 0;
        for(int e=1; e<=N; e++){
            if( max < dist[s][e]){
                max = dist[s][e];
            }
        }
        if(ans > max) ans = max;
    }
    cout << ans << endl;
}
int main(){
    InputData();
    Solve();	
    return 0;
}
