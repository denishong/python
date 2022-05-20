#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a;
    vector<int>v;
   for(int i=0; i<3; i++) {
		cin>>a;
    	v.push_back(a);
	}
    sort(v.begin(),v.end());
    cout<<v[1]<<endl;
    return 0;
}
