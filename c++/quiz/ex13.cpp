#include <iostream>
#include <functional>
using namespace std; 


int main()
{

	int n1=10;
	int n2=20;

	reference_wrapper<int> r1(n1);	
	reference_wrapper<int> r2(n2);	

	r1=r2;

	cout << n1 << ", ";
	cout << n2 << ", ";
	cout << r1 << ", ";
	cout << r2 << ", ";

}
