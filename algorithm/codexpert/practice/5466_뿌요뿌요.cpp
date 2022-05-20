#include <iostream>
#include <vector>
using namespace std;
#define MAXH (12)
#define MAXW (6)
char map[MAXH+2][MAXW+2];
int visit[MAXH+2][MAXW+2];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int Boom_cnt=0;
int Temp_cnt=0;
vector<pair<int,int>>Boom_tmp, Boom_vec;
void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
        if (map[nx][ny] == '.') continue;
        if (visit[nx][ny] == true) continue;
        if (map[x][y] != map[nx][ny]) continue;
        cout << "map[nx][ny] : " << map[nx][ny] << endl; 
        Temp_cnt++;
        visit[nx][ny] = true;
        Boom_tmp.push_back(make_pair(nx, ny));
        DFS(nx, ny);
    }
}

int Solve(){
    bool Flag;
    int ans=0;
    while(1){
        for(int i=1; i<=MAXH; i++){
            for(int j=1; i<=MAXW; j++){
                if(map[i][j] !='.' && visit[i][j]==false){
                    Temp_cnt=1;
                    Boom_tmp.push_back(make_pair(i,j));
                    visit[i][j]=true;
                    DFS(i,j);
                    if(Temp_cnt>=4){
                        Flag=true; //뿌요가 터졌다고 표시 
                        for(int i=0; i<Boom_tmp.size(); i++){
                            Boom_vec.push_back(Boom_tmp[i]); //해당 좌표를 옮겨주자 
                        }
                    }
                    Boom_tmp.clear();
                }
            }
        }

       for (int i = 0; i < Boom_vec.size(); i++){
            int x = Boom_vec[i].first;
            int y = Boom_vec[i].second;
 
            map[x][y] = '.';
        }
 
        for (int i = 11; i >= 1; i--){
            for (int j = 1; j <= 6; j++){
                if (map[i][j] == '.') continue;
                int Tmp = i;
 
                while (1){
                    if (Tmp == 11 || map[Tmp + 1][j] != '.') break;
 
                    map[Tmp + 1][j] = map[Tmp][j];
                    map[Tmp][j] = '.';
                    Tmp++;
                }
            }
        }
        if (Flag == true) ans++;
        else break;
    }
    return ans;    
}
void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, t, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분

        ans=Solve();//여기서부터 작성

        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}
