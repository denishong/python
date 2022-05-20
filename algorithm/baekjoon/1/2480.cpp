#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int cnt=0,sum=0,two;
	int a[4];
	//1.입력 받는 부분 
	for(int i=0; i<3; i++)
		cin>>a[i];

	//2.오름차순으로 정렬,가장 큰수를 사용해야해서 미리 정렬해준다 
	sort(a,a+3);
	if(a[0]==a[1] && a[0]==a[2] && a[1]==a[2]){
		cnt=2;
	}else if(a[0]==a[1] || a[0]==a[2] || a[1]==a[2]){
		cnt=1;
		if(a[0]==a[1]){
			two=a[0];
		}else if(a[0]==a[2]){
			two=a[0];
		}else if(a[1]==a[2]){
			two=a[1];
		}
	}

	if(cnt==2){
		sum=10000+a[0]*1000;
	}else if(cnt==1){
		sum=1000+two*100;
	}else if(cnt==0){
		sum=a[2]*100;
	}
	cout <<sum<<endl;
	return 0;
}
