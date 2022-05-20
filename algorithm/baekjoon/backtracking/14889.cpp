/*[baekjoon]14889번 스타트와 링크*/
#include <bits/stdc++.h>
using namespace std;
#define MAX ((int) 1e9+1)
int N;
int S[20][20];
bool team[20];
int minval = MAX;
void DFS(int idx, int cnt ){
    if( cnt == N/2){
        vector<int> start, link;
        int start_ability =0, link_ability =0;

        for(int i=0; i<N; i++) {
            if(team[i] == true)
                start.push_back(i);
            else
                link.push_back(i);
        }

        for(int i=0; i< (N/2); i++){
            for(int j=0; j< (N/2); j++){
                start_ability += S[start[i]][start[j]];
                link_ability += S[link[i]][link[j]];
            }
        }
        int diff = abs(start_ability - link_ability);
        if(minval > diff)
            minval = diff;

        return;
    }

    //앞서 재귀를 하면서 선택한 팀은 제외(중복 주의!! 시간 초과발생)
    for(int i=idx; i<N; i++){
        if(team[i] == false){
            team[i] =true;
            DFS(i+1, cnt+1);
            team[i] =false;
        }
    }
}
void Solve(){
    DFS(0,0);
    cout << minval<< endl;
}
void InputData(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> S[i][j];
}
int main(){
   InputData();
   Solve();
   return 0;
}
/*[baekjoon]14889번 스타트와 링크*/
