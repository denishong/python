#include <iostream>
using namespace std;

class Point
{
public:
	Point(int a=0, int b=0){}
};

int main()
{

	int a=1;
	
	Point(1);
//	Point(a);
	Point{a};

}
