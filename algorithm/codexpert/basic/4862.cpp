#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)

int N, M;//지하철역수, 목적역
int S[MAXN+2][MAXN+2];//[s][e]=시간

int path[MAXN+2];
int visited[MAXN+2];

void InputData(){
	cin >> N >> M;
	for (int s=1; s<=N; s++){
		for (int e=1; e<=N; e++){
			cin >> S[s][e];
		}
	}
}
void OutputData_visited(){
    cout << "output visited" << endl;
	for (int s=1; s<=N; s++){
			cout << visited[s] << " ";
		}
        cout << endl;
}

void OutputData_In(){
    cout << "output data " << endl;
	for (int s=1; s<=N; s++){
		for (int e=1; e<=N; e++){
			cout << S[s][e];
		}
        cout << endl;
	}
}


void OutputData(int m){

    if(m == 0) return;
    OutputData(path[m]);
    cout << m  << " " ;;
}

void InitData(){
    for(int i=1; i<=N; i++){
        visited[i] = 100 * 100 + 10;
    }
}

int BFS(){
    queue<int> q;
    q.push(1);
    visited[1] = 0;


    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int e=2; e<=N; e++){
            int ntime = visited[cur] + S[cur][e];
            cout << "visited[cur], S[cur][e] visited[e]" << visited[cur]<< S[cur][e] <<visited[e]<< endl;
            if(visited[e] <= ntime) continue;
            cout <<"e, ntime " << e << " " << ntime << endl;
            q.push(e);
            visited[e] = ntime;
            path[e] = cur;
        }

    } 

    return visited[M];
}


int main(){
	InputData();//입력

	//여기서부터 작성
    InitData();
    int ans = BFS();
    cout << ans << endl;    
    OutputData(M);
	return 0;
}
