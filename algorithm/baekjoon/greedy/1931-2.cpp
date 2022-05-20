#include <iostream>
#include <algorithm>
using namespace std;
struct meeting{
    int s;
    int e;
};
bool comp(meeting a, meeting b){
    if(a.e == b.e){
        return a.s < b.s;
    }else{
        return a.e < b.e;
    }
}
int main(){
	int N;
    struct meeting A[100001];
	int a,b, count=0, now =0;
	cin >> N;
	for( int i =0; i < N; i++){
		cin >> a >> b;
		A[i].s=a;
        A[i].e=b;
	}
	sort( A, A+N, comp);

	for( int i =0; i< N; i++ ){
		if( now <=  A[i].s ){
			now = A[i].e;
			count++;
		}
	}//for

	cout << count << endl;
	return 0;
}
