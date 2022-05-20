/*baekjoon 7569 토마토 BFS*/
#include <iostream>
#include <queue>
using namespace std;
#define max ((int)1e2+5)

int M,N,H ;//가로, 세로,상자수 
int map[max][max][max];
bool mapCheck[max][max][max];
int path[max][max][max];
int cnt;
int dz[6] = {0,0,0,0,-1,1};
int dy[6] = {-1,1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
struct Q{//입력 좌표 
	int z,y,x;
};
Q cur;
queue<Q>q;

bool isInside(int z, int y,int x){
    return ((z>=0 && z<H) && (y>=0 && y<N) && (x>=0 && x<M));
}

void Solve(){
    while(!q.empty()) {
        cur=q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = cur.z + dz[i];
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(isInside(nz,ny,nx) && map[nz][ny][nx]==0 && mapCheck[nz][ny][nx]==0 ){
                //mapCheck[nz][ny][nx] = 1;
                map[nz][ny][nx] = 1;
                q.push({nz,ny,nx});
                path[nz][ny][nx] = path[cur.z][cur.y][cur.x] + 1;
            }
        }
    }
}
void InputData(){
    cin >> M >> N >> H;
    for( int z=0; z < H; z++){
        for( int y=0; y < N; y++){
            for( int x=0; x < M; x++){
                cin >> map[z][y][x];
                if( map[z][y][x] == 1 ){
                    q.push({z,y,x}); 
                 }
             }
        }
    }
}
int main(){
    InputData();
    Solve();

    for( int z=0; z <H; z++){
        for( int y=0; y < N; y++){
            for( int x=0; x < M; x++){
                if( map[z][y][x] == 0 && path[z][y][x] == 0 ){
                    cout << -1 << endl;	
                    return 0;
                }
            }
        }
    }

    int ans = -1;
    for( int z=0; z < H; z++){
        for( int y=0; y < N; y++){
            for( int x=0; x < M; x++){
                if( path[z][y][x] > ans ){
                    ans = path[z][y][x];	
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
/*baekjoon 7569 토마토 BFS*/
