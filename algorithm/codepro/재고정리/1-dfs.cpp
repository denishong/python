#include <iostream>
using namespace std;

int N;//던진 회수 
int M;//출력 모양 
int num[10];
int used[10];
void DFS1(int n){//중복 순열 
    if(n >= N){
		for(int i=0; i<N; i++)
			cout<<num[i]<<' ';
		cout<<endl;
        return;
    }

    for(int i=1;i<=6; i++){
		num[n]=i;
        DFS1(n+1);
    }
}

void DFS2(int n,int s){//중복 조합 
    if(n >= N){
		for(int i=0; i<N; i++)
			cout<<num[i]<<' ';
		cout<<endl;
        return;
    }

    for(int i=s;i<=6; i++){
		num[n]=i;
        DFS2(n+1,i);
    }
}
void DFS3(int n){//순열 
    if(n >= N){
		for(int i=0; i<N; i++)
			cout<<num[i]<<' ';
		cout<<endl;
        return;
    }

    for(int i=1;i<=6; i++){
		if(used[i]) continue;
		used[i]=1;
		num[n]=i;
        DFS3(n+1);
		used[i]=0;
    }
}
void DFS4(int n,int s){//조합 
    if(n >= N){
		for(int i=0; i<N; i++)
			cout<<num[i]<<' ';
		cout<<endl;
        return;
    }

    for(int i=s;i<=6; i++){
		num[n]=i;
        DFS2(n+1,i+1);
    }
}

void Solve(){
	if(M==1){//중복 순열 
    	DFS1(0);
	}else if(M==2){//중복 조합
		DFS2(0,1);
	}else if(M==3){//순열 
		DFS3(0);
	}else{//조합 
		DFS4(0,1);
	}
}
void InputData(){
    cin >> M >>N;
}

int main(){
    InputData();
    Solve();
    return 0;
}
