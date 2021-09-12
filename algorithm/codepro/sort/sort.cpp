#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	int myints[] = {32,71,12,45,26,80,53,33};

	vector<int> myvector(myints, myints+8);

	//sort(myints, myints+8);
	sort(myvector.begin(), myvector.end());

	for(vector<int>::iterator it=myvector.begin(); it<myvector.end(); it++)
		cout << " " << *it;
	cout << '\n';

	return 0;
}
