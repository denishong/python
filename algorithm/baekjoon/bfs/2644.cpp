#include<iostream>
using namespace std;
#include<queue>
int n,m; // n: 전체 사람의 수, m:부모 자식들 간의 관계 개수
int num1, num2; // 촌수 계산해야하는 두사람 번호
int x, y;//부머 자식간의 관계
int depth[101];
int family[101][101];
bool visit[101];
queue <int> q;

void bfs(int i){
	visit[i] = true;
	q.push(i);
	int temp;
	while (!q.empty()){
		temp = q.front(); q.pop();
		for (int j = 1; j <= n; j++){
			if (family[temp][j] == 1 && !visit[j]){
				visit[j] = true;
				depth[j] = depth[temp] + 1;
				q.push(j);
			}
		}
	}
}

int main(){
	cin >> n; //전체 사람의 수
	cin >> num1 >> num2; // 촌수 계산해야하는 두사람 번호
	cin >> m; // 부모 자식간의 관계 개수

	int a, b;
	for (int i = 1; i <= m; i++){
		cin >> a >> b;
		family[a][b] = 1;
		family[b][a] = 1;
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= m; j++){
			cout<<family[i][j]<<' ';
		}
		cout<<endl;
	}


	bfs(num1);
	for(int i=1; i<=n; i++)
		cout<<depth[i]<<' ';
	cout<<endl;
	if (depth[num2] != 0)
		cout << depth[num2] << endl;
	else
		cout << "-1" << endl;
	return 0;
}
