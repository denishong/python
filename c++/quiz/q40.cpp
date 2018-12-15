#include <iostream>
using namespace std; 


int main()
{

	int v1;
	int v2;

	auto f1=[v1,&v2]() {};	
	//auto f2=[v1,&]() {};	
	auto f3=[&v1,=]() {};	


}
