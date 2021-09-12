/* baekjoon 13305 주유소 */
#include <iostream>
#include <string>

using namespace std;

#define Max 100001
long long diste[Max];
long long price[Max];

int main(){

	int N;
	int i,j;
	long long result=0;
	long long minPrice;
	bool check = false;
	cin >> N;

	for( i =0; i < N-1; i++){
		cin >> diste[i];
	}

	for( i =0; i < N; i++){
		cin >> price[i];
	}

			result += diste[0] * price[0];
	minPrice = price[0];
	for( i = 1; i < N-1 ; i++){
		if( price[i] > minPrice ){
			result += diste[i] * minPrice;
		}else{
			minPrice = price[i];
			result += diste[i] * minPrice;
		}
			
	} //for

	cout << result << endl;
	return 0;
}
/* baekjoon 13305 주유소 */
