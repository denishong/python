#include <iostream>
#include <string.h>

class Point{
public:
	void Print();
	Point();	
	int SetXY(int a, int b);
	int moveLeft();
	int moveRight();
private:
	int x,y;
};

Point::Point()
{
	x=50;
	y=50;
	Print();
}

void Point::Print()
{
	std::cout << "x :  " << x <<
	std::endl;
	std::cout << "y :  " << y <<
	std::endl;
}

int Point::SetXY(int a, int b)
{
	x=a;
	y=b;
}

int Point::moveLeft()
{
	x=x-1;
	Print();
}

int Point::moveRight()
{
	x=x+1;
	Print();
}

int main()
{
	Point p;
	p.moveLeft(); p.moveLeft();
	p.moveRight();p.moveLeft();
	return 0;
}
	
