#include <iostream>
#include <vector>
using namespace std;
#define MAXN 129

int N;
int sample[MAXN][MAXN];
int white = 0;
int blue = 0;

void InputData(void){
    cin >> N;
    for (int i=1; i<=N; i++){
        for ( int j=1; j<=N; j++){
            cin >> sample[i][j];
        }
    }
}
void func(int N, int a, int b){
    vector<pair<int, int>> v;
    int check, diff;
    if(N==1){
        if(sample[a][b] == 1){
            blue++;
        }else{
            white++;
        }
        return;
    }
    v.push_back({a,b});
    v.push_back({a,b + (N/2)});
    v.push_back({a + (N/2),b});
    v.push_back({a + (N/2),b + (N/2)});

    check = sample[v[0].first][v[0].second];
    diff = sample[v[0].first][v[0].second];

    for ( int i=0; i<N; i++){
        if(check != diff) break;
        for(int j=0; j<N; j++){
            if( check != sample[v[0].first + i][v[0].second + j]){
                diff = sample[v[0].first + i][v[0].second + j];
                func( N/2, v[0].first, v[0].second);
                func( N/2, v[1].first, v[1].second);
                func( N/2, v[2].first, v[2].second);
                func( N/2, v[3].first, v[3].second);
                break;
            }
        }
    }

    if ( diff != check){
        return;
    }else{
        if ( check == 1){
            blue++;
        }else{
            white++;
        }
        return;
    }
}
void Solve(void){
    func(N,1,1);
    cout << white << endl << blue << endl;
}
int main(void){
    InputData();
    Solve();
    return 0;
}
