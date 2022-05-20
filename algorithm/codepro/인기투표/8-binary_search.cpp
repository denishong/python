#include <iostream>
#include <algorithm>
using namespace std;

int N;//후보자수
int M;//투표참가인원
string name[100010];//투표용지에 써있는 이름
int score[100010];//점수
struct D {
	string name;
	int idx;
	int cnt;
};
struct D A[100010];
bool comp_name(D a, D b){
	return (a.name < b.name);
}
bool comp_cnt(D a, D b){
	return (a.cnt > b.cnt);
}
int binarySearch(int index){
    int s,e,result;
    s=0; e=N-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid].name==name[index]){
            return mid;
        }else if(A[mid].name>name[index]){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}
void Solve(){
    int index;
	sort(A,A+N,comp_name);
	for (int i = 0; i < M; i++){
		index=binarySearch(i);
        if(index!=-1)
            A[index].cnt+=score[i];
	}

	sort(A,A+N,comp_cnt);
    for (int i = 0; i < 3; i++){
        cout<<A[i].name<<' '<<A[i].cnt<<endl;
	}
}
void InputData(){
	string tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		A[i].name=tmp;
		A[i].idx=i;
		A[i].cnt=0;		
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> name[i] >> score[i];
	}
}

int main(){
	InputData();//	입력 함수
	Solve();
	return 0;
}