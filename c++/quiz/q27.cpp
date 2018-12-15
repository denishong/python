#include <iostream>
using namespace std; 

class Test
{
public:
	Test() {cout << "Test()" << endl;}
	~Test() {cout << "~Test()" << endl;}
};

int main()
{

	Test(), cout << "X" << endl;
	cout << "Y" << endl;
}

