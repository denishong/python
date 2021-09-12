#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e2)
int paper[MAXN+10][MAXN+10];
void FillPaper(int sh, int sw, int eh, int ew){
	for(int i=sh; i<eh; i++){
		for(int j=sw; j<ew; j++){
			paper[i][j]=1;
		}
	}
}
void InputData(){
	int N, sw, sh;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> sw >> sh;
		FillPaper(sh, sw, sh+10, sw+10);
	}
}
int isPossible(int sh, int sw, int eh, int ew){
	for(int i=sh; i<=eh; i++){
		for(int j=sw; j<=ew; j++){
			if(paper[i][j] == 0) return 0;
		}
	}
	return 1;
}
int Solve(){
	int maxarea=100, area=0;
	for(int sh=0; sh<MAXN; sh++){
		for(int sw=0; sw<MAXN; sw++){
			if(paper[sh][sw] == 0) continue;
			for(int eh=sh+1; eh<MAXN; eh++){
				for(int ew=sw+1; ew<MAXN; ew++){
					if(paper[eh][ew] == 0) break;
						area = (eh-sh+1) * (ew-sw+1);
					if(maxarea >= area) continue;
					if(isPossible(sh,sw,eh,ew)==0) break;
						maxarea = area;
				}
			}
		}
	}
	return  maxarea;
}
int main(void){
	int ans;
	InputData();
	ans=Solve();
	cout << ans;
	return 0;
}
