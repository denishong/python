#include <iostream>
using namespace std;

int main(){
	int A[27]={0,};
	string S;

	cin>>S;
	for(int i=0; i<S.size(); i++)
		A[S[i]-'a']++;

	for(int i=0; i<26; i++)
		cout<<A[i]<<' ';
	
	return 0;
}
