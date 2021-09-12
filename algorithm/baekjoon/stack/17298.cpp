#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n=0,i,j=0;
	int min =0;

	stack<int> s;
	int input[100001];


	cin >> n ;

	for(int i =0; i < n; i++)
		cin >> input[i];

	for(int i =0; i < n; i++)
	{
		for( j = i+1; j < n; j++)
		{
			if( input[i] < input[j] )
			{
				s.push( input[j] );
			}
		}

		if( s.empty() )
			cout << -1 << " ";
		else
		{
			if( s.size() == 1)
			{
				if( !s.empty() )
					cout << s.top() << " ";
				else
					cout << "-1" << " ";

			}
			else if( s.size() > 1)
			{
				min = s.top();
				while( s.size() != 0 )
				{
					if( s.size() > 1)
					{
					 	s.pop();
						if( s.top() < min ) min = s.top();
					}
					else if ( s.size() == 1 )
					{
						if( s.top() > min ) min = s.top();
						break;
					}
				}
			cout << min << " ";
			}
		}


		while( !s.empty() )
			s.pop();
	}

	cout << endl;
	return 0;
}
