#include <iostream>
using namespace std;
char str[10] = "ABCDEDF";

int main(){
	int i;
    for( int i=0; str[i]; i++ ){
        cout << str[i];
    }

    for( i=0; str[i]; i++ );
	cout << "i: " << i;
    return 0;
}
