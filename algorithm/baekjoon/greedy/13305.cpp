/* baekjoon 13305 주유소 */
#include <iostream>
using namespace std;

#define Max 100001
long long Distance[Max];
long long price[Max];
int N;

void InputData(){
    cin >> N;
    for(int i =0; i < N-1; i++)
        cin >> Distance[i];

    for(int i =0; i < N; i++)
        cin >> price[i];
}
void Solve(){
    long long result=0;
    long long minPrice;
 
    result += Distance[0] * price[0];
    minPrice = price[0];
    for(int i = 1; i < N-1 ; i++){
        if( price[i] > minPrice ){
            result += Distance[i] * minPrice;
        }else{
            minPrice = price[i];
            result += Distance[i] * minPrice;
        }
    }
    cout << result << endl;
}

int main(){
    InputData();
    Solve(); 
    return 0;
}
/* baekjoon 13305 주유소 */
