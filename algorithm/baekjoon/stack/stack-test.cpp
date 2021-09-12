#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int test;
    char aa;

	stack<int> s;

    if( !s.empty())
        cout << "Stack is empty" << endl;

	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	cout << s.size() << endl;
	cout << s.empty() << endl;
    s.pop();
    return 0;
}
