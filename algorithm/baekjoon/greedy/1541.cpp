/* baekjoon 1541 잃어버린 괄호*/
#include <iostream>
#include <string>

using namespace std;

int main(){

	string str;
	string tmp="";
	int i,j, result=0;
	bool  minus =false;
	cin >> str;

	for( i = 0; i <= str.size(); i++){

		if( str[i] == '+' || str[i] == '-' || str[i] == '\0' ){

			if( minus ){
				result -= stoi(tmp);
			}else{

				result += stoi(tmp);
			}

			if( str[i] == '-' )
				minus = true;
			tmp = "";
			continue;
		}
		tmp += str[i];
	} //for
	cout << result << endl;
	return 0;
}
/* baekjoon 1541 잃어버린 괄호*/
