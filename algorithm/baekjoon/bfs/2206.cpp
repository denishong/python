/*baekjoon 2206 벽 부수고 이동하기 BFS*/
#include <iostream>
#include <queue>

using namespace std;

#define max 1001 
typedef pair< pair<int, int>, int > triple;
int n, m ;// 세로 ,가로  
int map[max][max];
int mapCheck[max][max];
int wallCheck[max][max][2];
int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
bool check = 0;

bool isInside(int a, int b){
    return (a>=0 && a<n) && (b>=0 && b<m);
}


void bfs(){

    int cur_y = 0, cur_x = 0;
    bool broken = 0;
    queue< triple > q;
    q.push(make_pair(make_pair(cur_y, cur_x), 0));
    mapCheck[cur_y][cur_x] = 1;
    wallCheck[cur_y][cur_x][0] =true;

    while(!q.empty()) {
        triple tp = q.front();
        int cur_y = tp.first.first;
        int cur_x = tp.first.second;
        bool broken = tp.second;
        q.pop();

        //cout << "cur_y, cur_x broken : " << cur_y << cur_x << broken << endl;
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + d[i][0];
            int next_x = cur_x + d[i][1];
        
            //cout << "broken next_y, next_x, broken ,mapCheck[next_y][next_x]: " << next_y << next_x << broken <<  mapCheck[next_y][next_x] << endl;
            if(isInside( next_y , next_x ) && broken == 0 && map[next_y][next_x]==1 ){
            //cout << "before broken next_y, next_x, map[next_y][next_x]: " << next_y << next_x << map[next_y][next_x]<< endl;
                mapCheck[next_y][next_x] = mapCheck[cur_y][cur_x] + 1;
                wallCheck[next_y][next_x][0] = true;
                q.push( make_pair( make_pair(next_y, next_x), 1) );
            }
            else if(isInside( next_y , next_x ) && wallCheck[next_y][next_x][0] == false &&  map[next_y][next_x]==0){
            //cout << "after broken next_y, next_x, map[next_y][next_x]: " << next_y << next_x << map[next_y][next_x] << endl;
                mapCheck[next_y][next_x] = mapCheck[cur_y][cur_x] + 1;
                wallCheck[next_y][next_x][0] = true;
                q.push( make_pair(make_pair(next_y, next_x), 1) );
            }
        }
    }

}


void Print_mapCheck(){
    cout << endl;
    for( int i=0; i < n; i++){
        for( int j=0; j < m; j++){
            cout << mapCheck[i][j];
        }
        cout << endl;
    }
}

void Print_map(){
    printf("\n");
    for( int i=0; i < n; i++){
        for( int j=0; j < m; j++){
            printf("%d", map[i][j] );
        }
        printf("\n");
    }
}

int main(){

    scanf("%d %d", &n, &m);
    for( int i=0; i < n; i++){
        for( int j=0; j < m; j++){
            scanf("%1d", &map[i][j] );
        }
    }
    bfs();
    //Print_mapCheck();
    if( mapCheck[n-1][m-1] == 0){
        printf("-1\n");
    } else
    printf("%d\n",  mapCheck[n-1][m-1]);

    return 0;
}
/*baekjoon 2206 벽 부수고 이동하기 BFS*/
