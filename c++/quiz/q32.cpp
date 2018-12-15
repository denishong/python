#include <iostream>
using namespace std; 

class Test
{
public:
	Test()=default;

	Test(const Test&) {cout <<"copy" << endl;}
	Test(Test&&)	   {cout <<"move" << endl;}
};

int main()
{
	Test t1;
	Test t2;
	Test t3=t1;
	Test t4=static_cast<Test&&>(t1);
	Test t5=move(t2);
	Test t6=move_if_noexcept(t3);
	
}
