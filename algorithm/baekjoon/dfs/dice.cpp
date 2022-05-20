#include<iostream>
using namespace std;
int D[6];
int V[6];
int N=3;
void DFS(int n,int s){
	if(n==N){
		for(int i=1; i<=N; i++)
			cout<<D[i]<<' ';
		cout<<endl;
	return;
	}
	for(int k=s; k<=6; k++){
		if(V[k]=true) continue;
		D[n]=k;
		DFS(n+1, k+1);
		V[k]=false;
		D[n]=0;
	}
}
int main(void){
	DFS(1,1);
	return 0;
}
