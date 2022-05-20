#include <iostream>
#include <queue>
using namespace std;
#define MAXV (20010)
#define MAXE (300010)
#define INF (int)1e4
int N, M, S;//세로, 가로,시작점 
int map[MAXV][MAXV];
int count=0,ans=-1;
void Solve(){
	for (int s=1; s<=N; s++){
		for (int e=1; e<=N; e++){
			if(s==e) map[s][e]=0;
			else if(map[s][e]==0) map[s][e]=INF;
		}
	}
	
	for(int k=1; k<=N; k++){	
		for(int s=1; s<=N; s++){	
			for(int e=1; e<=N; e++){	
				if(map[s][e] > map[s][k] + map[k][e]){
					map[s][e] = map[s][k] + map[k][e];
				}
			}
		}
	}
			

	for(int s=1; s<=N; s++){	
		if(s==S){
			for(int e=1; e<=N; e++){	
				if(map[s][e]==INF) cout<<"INF"<<endl;
				else cout<<map[s][e]<<endl; 
			}
		}
	}
}
void InputData(){
	int A,B,D;
	cin>>N>>M;
	cin>>S;
	for (int i=0; i<M; i++){
		cin>>A>>B>>D;
		map[A][B]=map[B][A]=D;
	}
}
int main(){
	InputData();
	Solve();
	return 0;
}
