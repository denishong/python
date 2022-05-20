#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	vector<int>v;
	for(int i=0; i<10; i++){
		int tmp=10*i;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for(int i=0; i<10; i++){
		cout<<v[i]<<endl;
	}
	return 0;
}
