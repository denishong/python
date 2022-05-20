#include <iostream>
using namespace std;
int N;//던진횟수
int M;//출력모양
int num[10];
void DFS1(int n){
	if(n>=N){
		for(int i=0; i<N; i++){
			cout << num[i] << ' ' ;
		}
		cout << endl;
		return;
	}
	for(int i=1; i<=6; i++){
		num[n]=i;
		DFS1(n+1);
	}
}
void DFS2(int n, int s){
	if(n>=N){
		for(int i=0; i<N; i++){
			cout << num[i] << ' ';
		}
		cout << endl;
		return;
	}
	for(int i=s; i<=6; i++){
		num[n]=i;
		DFS2(n+1,i);
	}
}
int used[10];
void DFS3(int n){
	if(n>=N){
		for(int i=0; i<N; i++){
			cout << num[i] << ' ';
		}
		cout << endl;
		return;
	}
	for(int i=1; i<=6; i++){
		if(used[i]) continue;
		used[i]=1;
		num[n]=i;
		DFS3(n+1);
		used[i]=0;
	}
}
void Solve(void){
	if(M==1){//중복순열 
		/*for(int i=1; i<=6; i++){
			for(int j=1; j<=6; j++){
				for(int k=1; k<=6; k++){
					cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}*/
		DFS1(0); //던진 횟수 	
	}else if(M==2){//중복조합 
		/*for(int i=1; i<=6; i++){
			for(int j=i; j<=6; j++){
				for(int k=j; k<=6; k++){
					cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}*/
		DFS2(0,1);
	}else{//순열 
		/*for(int i=1; i<=6; i++){
			for(int j=i; j<=6; j++){
				if(i==j) continue;
				for(int k=j; k<=6; k++){
					if((i==j) || (j==k)) continue;
					cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}*/
		DFS3(0);
	}
}
void InputData(){
	cin >> N >> M;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	Solve();//여기서부터 작성

	return 0;
}
