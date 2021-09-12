/*[실전][4838]연속부분최대곱*/
#include <bits/stdc++.h>
using namespace std;

int N;
double D[10000+10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}
double SolveN3(){
    double maxv=0, mul;
    for(int s=0; s<N; s++){
        for(int e=s; e<N; e++){
            mul =1;
            for(int k=s; k<=e; k++){
                mul *= D[k];
				cout << "s, e, k, mul" << ":" << s <<" " << e << " " << k << " " <<  mul <<  endl;
            }
            if(maxv < mul) maxv =mul;
        }
    }
    return maxv;
}
double SolveN2(){
    double maxv=0, mul;
    for(int s=0; s<N; s++){
        mul =1;
        for(int k=s; k<N; k++){
            mul *= D[k];
			//cout << "s, k, mul" << ":" << s <<" " << k << " " <<  mul <<  endl;
            if(maxv < mul) maxv =mul;
        }
    }
    return maxv;
}
int main(){
    double ans = -1;
	cout.precision(3);
	cout << fixed;
    InputData();
    ans = SolveN2();
	cout << ans << endl;
    return 0;
}
/*[실전][4838]연속부분최대곱*/
