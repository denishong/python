#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
	int n=0,i = 0, count = 0;

	stack<char> s;
	char input[200];


	while( fgets(input, sizeof(input), stdin ) != NULL )
	{
		count = 0;
		if(input[0] == '.' ) break;

		for( i=0; i < strlen(input); i++)
		{
			if( input[i] == '(' || input[i] == '[' )
			{
				s.push( input[i] );
				//cout << "stack : " << s.top() << endl;
			}
			else if( input[i] == ')' || input[i] == ']' )
			{
				if( s.empty() ) 
				{
					count++;
					break;
				}
				else if( !s.empty() )
				{
					if( s.top() == '(' && input[i] == ')' )
					{
					//	cout << "stack is : " << s.top() << endl;
						s.pop();
					}
					else if( s.top() == '[' && input[i] == ']' )
					{
					//	cout << "stack is : " << s.top() << endl;
						s.pop();
					}
					else if( s.top() == '(' && input[i] == ']' )
					{
						count++;
						break;
					}
					else if( s.top() == '[' && input[i] == ')' )
					{
						count++;
						break;
					}
					else
					{
						count++;
						break;
					}
				}

			}
		}

		if( s.empty() && count == 0 )
			cout << "yes\n";
		else 
			cout << "no\n";

		if( !s.empty() )
		{
			//cout << "Stack is not empty!!" << endl;
			while( !s.empty() )
				s.pop();

			//cout << "Stack size is !!" << s.size() << endl;
		}
	}

	return 0;
}
