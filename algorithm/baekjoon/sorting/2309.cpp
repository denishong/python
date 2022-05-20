/*baekjoon 2309 */
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1001

int	D[MAXN+10]; 

int Solve(){
	int sum=0,tmp;
	sort(D, D+9);
	for(int i=0; i<9; i++){
		sum+=D[i];
	}
	for(int i=0; i<8; i++){
		for(int j=i+1; j<9; j++){
			if(sum-D[i]-D[j]==100){
				for(int k=0; k<9; k++){
					if(k==i || k==j) continue;
						cout<<D[k]<<endl;
				}	
				return 0;
			}
		}
	}
	return 0;
}
void InputData(){
	for(int i=0; i<9; i++)
		cin >> D[i];
}
int main(){
	InputData();
	Solve();
	return 0;
}
/*baekjoon 2309*/ 
