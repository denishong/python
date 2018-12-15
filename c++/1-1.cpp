#include <iostream>
#include <string.h>

class Person{
public:
	int age;
	char name[10];
};

int main()
{
	Person kim;
	kim.age=23;
	strcpy(kim.name, "Sunghoon");
	std::cout << "name : " << kim.name <<std::endl;

	std::cout << "age :   " <<kim.age
	<<std::endl;

	return 0;
}
	
