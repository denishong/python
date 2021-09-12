/*baekjoon 1181 단어 정렬*/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 20000
int	N;
string Data[MAX+10];

void InputData(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> Data[i];
	}
}
void OutputData(){
	for( int i=0; i<N; i++){
		cout << Data[i]<< endl;
	}
}
bool comp(string i, string j){ 
    if (i.size() == j.size()){
        return (i < j);
    }
    else{
        return i.size() < j.size();
    }
}
void Solve(){
	cout << Data[0] << endl;	
	for(int i=0; i<N-1; i++){
		if(Data[i].compare(Data[i+1]) ){
			cout << Data[i+1] << endl;	
		}
	}
}
int main()
{
	InputData();
	sort( Data, Data+N, comp);
	Solve();
	return 0;
}
/*baekjoon 1181 단어 정렬*/
