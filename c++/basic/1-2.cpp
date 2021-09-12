#include <iostream>
#include <string.h>

class Point{
public:
//	int x,y;
	void Print();
	Point();	
	void setPrint(int a, int b)
	{
		x = a;
		y = b;
	}

private:
	static int x,y;
};

Point::Point()
{
	x=100;
	y=100;
}

void Point::Print()
{
	std::cout << "x :  " << x << "y :  " << y << std::endl;
}

int main()
{
	Point point1;
	point1.x=50;
	point1.Print();
	return 0;
}
	
