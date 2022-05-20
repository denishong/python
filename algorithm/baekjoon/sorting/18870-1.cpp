#include <bits/stdc++.h>
using namespace std;
int N;
int X;
vector<int> v;
vector<int> v_copy(v);
void OutputData(){
    for(vector<int>::iterator it=v_copy.begin(); it != v_copy.end(); ++it){
        cout << *it << ' ' ;
    }
    cout << endl;
}
void Solve(){
	//원본 벡터 복사
    vector<int> v;
    vector<int> v_copy(v);
    OutputData();
	//정렬
	sort(v_copy.begin(), v_copy.end());
    OutputData();
	//중복 제거
	auto endidx = unique(v_copy.begin(), v_copy.end());
	//벡터 크기 조절(쓰레기 값 제거)
	v_copy.erase(endidx, v_copy.end());
	//원하는 값이 처음 등장하는 위치 찾기(오름차순 정렬 필수)
	for (int i = 0; i < N; i++)
	{
		auto idx = lower_bound(v_copy.begin(), v_copy.end(), v[i]);
		cout << idx - v_copy.begin() << " ";
	}
}
void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> X;
        v.push_back(X);
    }
}
int main()
{
    InputData();
    Solve();
	return 0;
}
