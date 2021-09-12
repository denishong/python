/*baekjoon 7569 토마토 BFS*/
#include <bits/stdc++.h>
using namespace std;
#define max ((int)1e2+5)

int M,N,H ;//가로, 세로,상자수 
int mmap[max][max][max];
bool mapCheck[max][max][max];
int path[max][max][max];
int cnt;
int dz[6] = {0,0,0,0,-1,1};
int dy[6] = {-1,1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
queue<pair<pair<int,int>,int>> q;


bool isInside(int z, int y,int x){
    return ((z>=0 && z<H) && (y>=0 && y<N) && (x>=0 && x<M));
}

void Solve(){
    int x,y,z,nx,ny,nz;
    while(!q.empty()) {
        z = q.front().first.first;
        y = q.front().first.second;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            nz = z + dz[i];
            ny = y + dy[i];
            nx = x + dx[i];

            if(isInside(nz,ny,nx) && mmap[nz][ny][nx] == 0 && mapCheck[nz][ny][nx] == 0 ){
                mapCheck[nz][ny][nx] = 1;
                q.push( make_pair(make_pair(nz, ny),nx));
                path[nz][ny][nx] = path[z][y][x] + 1;
            }
        }
    }
}
void InputData(){
    cin >> M >> N >> H;
    for( int z=0; z < H; z++){
        for( int y=0; y < N; y++){
            for( int x=0; x < M; x++){
                cin >> mmap[z][y][x];
                if( mmap[z][y][x] == 1 ){
                    q.push(make_pair(make_pair(z,y),x)); 
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
                if( mmap[z][y][x] == 0 && path[z][y][x] == 0 ){
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
