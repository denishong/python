#include <iostream>
using namespace std;

int add_recur(int a)
{
	if(a >= 1){
		return a+add_recur(a-1);
	}else{
		return 0;
	}
}

int add(int a){
	int total =0;
	for(int i=1; i<=a; i++){
		total += i;
	}
	return total;
}

int main()
{
    int n;
    cin >> n; 

	//cout << add_recur(n) <<endl;
	cout << add(n) << endl;	
    return 0;
}
