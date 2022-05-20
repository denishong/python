#include <iostream>
using namespace std;

int N=5;
int main(){
	
	for(int s =1; s<N; s++){
		for(int e=s; e<N; e++){
			int mul =1;
			for(int k=s; k<=e; k++){
				mul *= k;
				cout << "mul, k : " << mul << " " << k << endl;
			}
		}
	}

}
