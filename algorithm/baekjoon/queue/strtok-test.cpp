#include <iostream>
#include <string.h>

using namespace std;

int main(){

    char str[100];
    char txt[100];

	cin >> str;

	char *ptr= strtok(str, "[ , " );
	while(ptr != NULL){
    cout << atoi(ptr) <<endl; 
	ptr = strtok(NULL, "[ , ");
	}

    return 0;
}
