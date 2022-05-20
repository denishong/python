#include<iostream>
using namespace std;

string aTest[10]={"amazing","mazing"};
string bTest="ssslkdfj";
int main(){
	for(int i=0; i<aTest.size; i++){
	if(aTest[i]>bTest)
		cout << aTest[i] <<endl;
		aTest[i]=bTest;
		cout << aTest[i] <<endl;
	}
	return 0;
}
