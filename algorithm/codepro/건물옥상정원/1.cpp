#include <iostream>

using namespace std;

#define Max 80000

int main(){

	int N;
	int H[Max];
	int i,j,sum;

	cin >> N;
	for( i = 0; i < N; i++){
		cin >> H[i];
	}

	for( i=0; i<N; i++){
		for( j=i+1; j<N; j++){
			if( H[i] > H[j]){
				sum++;
			}else{ break; }
		}
	}

	cout << sum << endl;
	return 0;
}
