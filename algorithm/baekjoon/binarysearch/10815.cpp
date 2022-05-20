/*[10815] 숫자카드*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)5e5+10) 
int N; 
int A[MAXN]; 
int M; 
int B[MAXN]; 
int Temp[MAXN];

void InputData() { 
    cin >> N;
    for(int i=0; i<N; i++) { 
        cin >> A[i]; 
    } 
    cin >> M;
    for(int i=0; i<M; i++) { 
        cin >> B[i]; 
    } 
} 
bool check(int a){
    int s, e, mid;
    s=0;
    e=N-1;
    while(s<=e){
        mid =(s+e)/2;
       //cout << "a:"  << a << " s: " << s << " e: " << e << endl;
        if(a == A[mid]) return 1;
        else if( a > A[mid] ) s = mid +1;
        else e = mid -1;
    }
    return 0;
}
void Solve(){
    sort(A,A+N);
    for(int i=0; i<M; i++) { 
        cout << check(B[i]) << ' ';
    } 
    cout << endl;
}
int main() { 
    InputData(); 
    Solve();
    return 0; 
} 
/*[10815] 숫자카드*/
