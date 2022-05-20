#include <iostream>
using namespace std;

int main(void){
	int Data;
	cin >> Data;

	while(Data>0){
		cout << Data%10 << endl;
		Data /=10;
	}
	return 0;
}
