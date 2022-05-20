/*baekjoon 2839 설탕 배달*/
#include <iostream>
using namespace std;
int N; // 설탕 무게 

void InputData(){
    cin >> N;
}
void Solve()
{
    int total = 0;
    int tmp = 0;

    if( N%5 == 0 ){
        cout <<  N/5 << endl;
    }else{
        tmp = N/5;
        do{
            if((N - tmp*5)%3 == 0){
                cout << tmp + (N -5*tmp)/3 << endl;
                break; 
            }
            tmp--;
            }while(tmp >=0 );
    }
    if( tmp == -1 )
    cout << "-1" << endl;
}
int main()
{
    InputData();
    Solve();
    return 0;
}
/*baekjoon 2839 설탕 배달*/
