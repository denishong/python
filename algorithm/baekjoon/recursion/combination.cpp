#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> subset;
void search(int k){
	if(k == n+1){
		//부분집합을 처리한다
		for(vector<int>::iterator it=subset.begin(); it != subset.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}else{
		//k를 부분집합에 포함시킨다
		subset.push_back(k);
		cout << __LINE__  << ' ' << "k: " << k <<endl; 
		search(k+1);
		cout << __LINE__  << ' ' << "k: " << k <<endl; 
		subset.pop_back();
		cout << __LINE__  << ' ' << "k: " << k <<endl; 
		//k를 부분집합에 포함시키지 않는다
		search(k+1);
		cout << __LINE__  << ' ' << "k: " << k <<endl; 
	}
}
int main(){
	cin >> n;
	search(1);
	return 0;
}
