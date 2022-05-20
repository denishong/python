#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct D{
	int idx;
	string name;
};
bool comp(D a, D b){
	return a.name<b.name;}
bool complower(D a, string b){
	return a.name<b;}
int main() {
	D P[100];
	string arr[] = {"bannana","apple","can","lion","tiger","bear"}; 
	string check[] = {"bannana","apple","can"};
	
	for(int i=0;i<sizeof(arr)/sizeof(string);i++){
		P[i].idx=i;
		P[i].name=arr[i];
	}

	sort(P,P+sizeof(arr)/sizeof(string),comp);
	for(int i=0;i<sizeof(check)/sizeof(string);i++)
		cout<<lower_bound(P,P+sizeof(arr)/sizeof(string),check[i], complower)-P<<endl;
	return 0;
}
