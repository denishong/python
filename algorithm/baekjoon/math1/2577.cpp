#include <iostream>
using namespace std;

int main(){
    int A,B,C,total;
    int count[10]={0};
    cin>>A>>B>>C;

    total = A*B*C;
    while(total > 0){
        count[total%10]++;
        total = total/10;
    }

    for(int i=0; i<10; i++)
        cout<<count[i]<<endl;
    return 0;
}