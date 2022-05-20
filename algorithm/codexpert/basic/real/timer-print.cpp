#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    for(int i=1; ; i++){
        cout << "timer of integer : " << i << endl;
        sleep(0.1);
    }
    return 0;
}
