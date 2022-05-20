#include <iostream>
#include <vector>
using namespace std;

int main(void){
	vector <int> v;
	for( int i=1; i<=10; i++){
		v.push_back(i);
	}


	for( int i=0; i<v.size(); i++)
		cout << v[i] << ' '; 

	cout << endl;

	while(!v.empty()){
		cout << v.back() << ' '; 
		v.pop_back();
	}
	return 0;
}

