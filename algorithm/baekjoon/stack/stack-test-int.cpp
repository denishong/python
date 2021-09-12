#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int test;
    char aa;

	stack<int> s;

	if( s.top() )
		cout << "Hello !!" ;
    if( !s.empty())
        cout << "Stack is empty" << endl;
    s.top();
	s.push(1);
	s.push(2);
	s.push(4);
	s.push(10);
	s.push(5);

	while( s.size() != 0 )
	{
        cout << "stack is empty? " << s.empty() << endl;
        cout << "stack size" << s.size() << endl ;
		cout << "stack :  " <<	s.top() << endl;
		s.pop();
	}
    return 0;
}
