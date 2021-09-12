/*dequeue test*/
#include <iostream>
#include <deque>

using namespace std;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int i=0,j=0;
	int N; // N명 
	cin >> N;


	cout << endl<< "dequeue push back and pop back" << endl;
	for(i =1; i <= N; i++ ){
		dq.push_front(i);
	}

	for ( i=1; i <= N; i++ ){
		cout << dq.front() << ' ';
		dq.pop_front();
	}


	cout << endl<< "dequeue push front and pop front" << endl;
	for(i =1; i <= N; i++ ){
		dq.push_back(i);
	}

	dq.push_back(dq.front());
	dq.pop_front();
	for ( i=1; i <= N; i++ ){
		cout << dq.front() << ' ';
		dq.pop_front();
	}

	cout << endl;
	cout << endl<< "dequeue front" << endl;

	for(i =1; i <= N; i++ ){
		dq.push_back(i);
	}

	for(j=1; j<=N; j++){
		dq.push_back(dq.front());
		dq.pop_front();
		for ( i=1; i <= N; i++ ){
			cout << dq.front() << ' ';
		dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << endl;
	}


	cout <<endl<< "dequeue back" << endl;
	for(i =1; i <= N; i++ ){
		dq.push_front(i);
	}

	for(j=1; j<=N; j++){
		dq.push_front(dq.back());
		dq.pop_back();
		for ( i=1; i <= N; i++ ){
			cout << dq.back() << ' ';
			dq.push_front(dq.back());
			dq.pop_back();
		}
		cout << endl;
	}



  return 0;
}
