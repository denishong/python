#include <iostream>
using namespace std;

int main(void){
	int h,m,d;
	int totalm;
	cin >> h>>m;
	cin >>d;
	totalm=m+d;
	h+=totalm/60;
	m+=d;
	cout <<h%24<<' '<<m%60<<endl;
	return 0;
}
