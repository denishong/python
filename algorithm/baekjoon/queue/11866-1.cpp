/*baekjoon 11866 queue*/
#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int i=0,j=0;
	int N; // N명 
	int K; //K번째 제거 
	cin >> N;
	cin >> K;



    for(i =1; i <= N; i++ ){
        q.push(i);
    }

    cout << "<";
    while( !q.empty() ){
        for(i=0; i<K-1; i++){
            q.push( q.front() );
            if(!q.empty()){  q.pop(); }
            j++;
        }

        j++;
        if( !(j%K) ) {

            if(q.size() != 1)
                cout << q.front() << ", ";
            else if(q.size() == 1)
                cout << q.front();

            if(!q.empty()){
                q.pop(); }
        }
    }

    cout << ">" << endl;


	return 0;
}
