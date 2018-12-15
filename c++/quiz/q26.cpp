#include <iostream>
using namespace std; 

class Point 
{
public:
	int x, y;
};

int main()
{
	Point().x=10;
	cout << &Point() << endl;
	Point& r1=Point();
	const Point& r2=Point();
}

