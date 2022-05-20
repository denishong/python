#include <iostream>
using namespace std;
void Solve(){
	int num,layer=0;
	cin>>num;
	for(int sum=2; sum<=num; layer++){
		sum+=6*layer;
		}
		if(num== 1) layer=1;
			cout << layer << endl;
}

int main(){
	Solve();
	return 0;
}
