#include <iostream>
#include <queue>
using namespace std;

int dist[101];
int Next[101];

void Solve(){
	dist[1]=0;
	queue<int>q;
	q.push(1);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int y=x+i;
			if(y>100) continue;
			y=Next[y];
			if(dist[y] == -1){
				dist[y]=dist[x]+1;
				cout<<"i,x,y,dist[y];"<<i<<' '<<x<<' '<<y<<' '<<dist[y]<<endl;
				q.push(y);
			}
		}
	}
	cout<<dist[100]<<endl;
}

void InputData(){
	int n,m;
	cin >> n>>m;
	for(int i=1; i<=100; i++){
		Next[i]=i;
		dist[i]=-1;
	}
	for(int i=1; i<=n+m; i++){
		int x,y;
		cin>>x>>y;
		Next[x]=y;
	}
}

int main(){
	InputData();
	Solve();
	return 0;
}
