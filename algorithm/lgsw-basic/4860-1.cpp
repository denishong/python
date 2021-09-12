#include <iostream>
#include <queue>
using namespace std;

int N, M;
int s[200+10];
int e[200+10];
int sol[100+10];
int sel[100+10];

int _queue[100+10];
int Rp = 0, Wp = 0;

int In_Queue(int d){
	_queue[Wp++] = d;
	return 1;
}

int Out_Queue(void){
	return _queue[Rp++];
}

void InputData()
{
	cin >> N >> M;
	for(int i=1; i<=M; i++)
	{
		cin >> s[i] >> e[i];
	}
}

void OutputData()
{
	cout << sol[0];
	for(int i=1; i<N; i++)
	{
		cout << " " << sol[i];
	}
} 

void BFS(){
	int i, t, d;
	In_Queue(1);
	sel[1] = 1;

	while( Wp > Rp) {
		int temp = Out_Queue();
		cout << temp << " ";
		for (i = 1; i <= M; i++) {
			if (( temp == s[i] && sel[e[i]] == 0)) d = e[i];
			else if(( temp == e[i] ) && ( sel[s[i]] == 0 )) d = s[i];
			else continue;

			In_Queue(d);
			sel[d] = 1;
		}   
	}   
}

int main()
{
	InputData();// 입력받는 부분

	// 여기서부터 작성
	BFS();
	//OutputData();// 출력하는 부분
	return 0;
}
