#include <iostream>
using namespace std;

int main(){
    int A[11]={0};
    int check[42]={0};
    int count=0;

    for(int i=0; i<10; i++)
        cin>>A[i];

    for(int i=0; i<10; i++)
        check[A[i]%42]++;

    for(int i=0; i<42; i++){
        if(check[i] != 0)
            count++;
    }
        printf("%d\n", count);
    return 0;
}