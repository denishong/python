#include <iostream>

using namespace std;

int main(){

    int val;

    while(1){
        cout << " input number : ";
        cin.clear();
        cin >> val;
        cout << "cin.fail(): " << cin.fail() << '\n';
        if( cin.fail()){

            cin.clear();
            cin.ignore(256, '\n');
            cout << "input wrong number! please input again." << endl;
        }
        else

            break;
    }
    return 0;
}
