#include <iostream>
#include <queue>

using namespace std;

int main(){

    int a=10, b = 12,c = 20,d =22;
    queue< pair< pair<int, int>, pair<int, int> > > q;


    q.push( make_pair( make_pair(a,b), make_pair(c,d)) );


    cout << q.front().first.first << '\n';
    cout << q.front().first.second<< '\n';
    cout << q.front().second.first << '\n';
    cout << q.front().second.second<< '\n';
    q.pop();

    a=13, b = 32,c = 55,d =52;
    q.push( make_pair ( make_pair(a,b), make_pair(33,d+1)) );

    cout << q.front().first.first << '\n';
    cout << q.front().first.second<< '\n';
    cout << q.front().second.first << '\n';
    cout << q.front().second.second<< '\n';
    return 0;
}
