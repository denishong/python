/*baekjoon 10866 dequeue*/
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;
#define MAX_N 100

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


    int n,i,dt;
    char str[20];
    cin >> n;

    deque<int> dq;


    for(i =0; i < n; i++ ){

        cin >> str;

        if( !strcmp(str, "push_front") ){
            cin >> dt;
            dq.push_front(dt);
        }else if( !strcmp(str, "push_back") ){
            cin >> dt;
            dq.push_back(dt);
        }else if( !strcmp(str, "pop_front") ){
            if(!dq.empty() ){
                cout << dq.front() << '\n';
                dq.pop_front();
            }else{
                cout << "-1" << '\n';
            }
        }else if( !strcmp(str, "pop_back") ){
            if(!dq.empty() ){
                cout << dq.back() << '\n';
                dq.pop_back();
            }else{
                cout << "-1" << '\n';
            }
        }else if( !strcmp(str, "size") ){
            cout << dq.size() << '\n';
        }else if( !strcmp(str, "empty") ){
            cout << dq.empty() << '\n';
        }else if( !strcmp(str, "front") ){
            if(!dq.empty() ){
                cout << dq.front() << '\n';
            } else {
                cout << "-1" << '\n';
            }
        }else if( !strcmp(str, "back") ){
            if(!dq.empty() ){
                cout << dq.back() << '\n';
            } else {
                cout << "-1" << '\n';
            }
        }
    }

    return 0;
}
