#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	string arr[] = {"bannana","apple","can","lion","tiger","bear"}; 
	string check[] = {"bannana","apple","can"};
	sort(arr,arr+sizeof(arr)/sizeof(string));
	for(int i=0;i<sizeof(arr)/sizeof(string);i++)
		cout<<arr[i]<<endl;

	for(int i=0;i<sizeof(check)/sizeof(string);i++)
		cout<<lower_bound(arr,arr+sizeof(arr)/sizeof(string),check[i])-arr<<endl;
	return 0;
}
