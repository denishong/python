#include<iostream>
#include<map>
using namespace std;
map<string,int,int>m;
int main(void){
	int N;
	string name;
	int tmp,cnt;
	//m.insert({"Alice",100});
	//m.insert({"Bob",200});
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>name>>tmp>>cnt;
		m.insert({name,tmp,cnt});
	}
	for(auto iter:m){
		cout<<iter.first<<' '<<iter.second<<endl;
	}
	for(auto i=m.begin();i!=m.end(); i++)
		cout<<i->first <<' '<<i->second<<endl;
	return 0;
}
