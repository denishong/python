#include <iostream>
using namespace std;
int N;//마을 수
int A[100000+10];//마을 위치
int B[100000+10];//잡힌 물고기 양
bool isPossible(int m){
    long long need = 0;
    for (int i=0; i<N-1; i++){
        need = need + B[i] - m;
		//cout << "i,need,B[i],m:" << i <<' '<<need<<' '<<B[i]<<' ' << m << endl;
        if (need < 0){//부족한 경우 (무조건 이웃마을에서 빌려와야 함)
            need -= A[i+1] - A[i];//도로 이용 세금 포함해야 함
        }
        else{//남는 경우(선택적으로 이웃마을에 보내야 함, 도로이용 요금이 더 많으면 못보냄)
            need -= A[i+1] - A[i];//도로 이용 세금 포함해야 함
            if (need < 0) need = 0;//세금이 더 많아서 음수가 되면 안보냄
        }
    }
	cout << "need,B[i],m:" << need<<' '<<B[N-1]<<' ' << m << endl;
    return (need + B[N-1] - m) >= 0;
}
int Solve(){
    int s=0, e=0, sol=1;
    //1.잡힌 물고기 양 중 max값(e)
    for (int i=0; i<N; i++){
        if (e < B[i]) e = B[i];
    }
    //2.이진탐색 upper bound 구하기(입양 가능한 경우 중 최댓값), 적게 입양할수록 가능함
    while (s <= e){
        int m = (s+e)/2;
        if (isPossible(m)){
            sol=m;
            s=m+1;
        }
        else{
            e=m-1;
        }
    }
    return sol;
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i] >> B[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	ans=Solve();
	cout << ans << "\n";//출력하는 부분
	return 0;
}
