#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 1e6)

int main()
{
    int i=0, length=0;
    char str[MAXN+10];

    cin >> str;
    cout << str;
    while( str[i] != '\0'){
        i++;
        if (str[0] == ' ' && str[1] == '\0'){
			break;
		}else if(i == 0 && str[0] ==' '){

		}else if( str[i] == ' '){
			length++;
		}

	}

	if( str[i] == '\0' && str[i-1] != ' '){
		length++;
	} else if( str[i] =='\0' && str[i-1] == ' '){
	}

    cout << length;
    return 0;
}
