#include <iostream>
using namespace std;

int main(void){
    for(int i=0; i<10; i++){
        if(i==5) break;
        cout << "test i: " << i << endl;
    }
    return 0;
}
