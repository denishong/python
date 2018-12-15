#include <iostream>
using namespace std; 

struct Point1
{
	int x,y;
};

struct Point2
{
	int x,y;
	Point2()=default;
};
struct Point3
{
	int x,y;
	Point3() {};
};
struct Point4
{
	int x,y;
	void set(int a, int b) { x=a; y=b;};	
};

int main()
{
	Point1 p1={1,1};
	Point2 p2={1,1};
	Point3 p3={1,1};
	Point4 p4={1,1};

}
