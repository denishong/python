// vector::begin/end
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int N;
    int x,y;
    vector< pair<int,int> > v;


    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> x >> y;
        v.push_back( make_pair(x, y) );
    }

    cout << "v contains:";
    cout << "v size:" << v.size() << endl;
    for (int i=0; i < v.size(); i++){
        cout << "first, second: " <<  v[i].first << ' ' << v[i].second; 
        cout << '\n';
    }

    sort(v.begin(), v.end());
    cout << "begin : " << v.front().first << '\n' ;

    cout << "v sorting:" << '\n';
    for (int i=0; i < v.size(); i++){
        cout << "first, second: " <<  v[i].first << ' ' << v[i].second; 
        cout << '\n';
    }

    return 0;
}
