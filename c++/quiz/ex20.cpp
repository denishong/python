#include <iostream>
using namespace std;

class Test 
{
	Object obj;
public:
	void setObject(Object o){obj=move(o);}
};

int main()
{
	Test t;

	Object obj;

	t.setObject(obj);	
	t.setObject(move(obj));	

}
