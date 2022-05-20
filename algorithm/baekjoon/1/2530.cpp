#include <iostream>
using namespace std;

int main(void){
	int h,m,s,d;
	int totalm,totals;
	cin >>h>>m>>s;
	cin >>d;
	s+=d;
	m=m+s/60;
	h+=m/60;
	cout <<h%24<<' '<<m%60<<' '<<s%60<<endl;
	return 0;
}
