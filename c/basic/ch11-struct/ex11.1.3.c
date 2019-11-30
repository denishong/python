#include <stdio.h>

int main()
{
	struct MYT{
		char *name;
		int age;
		float height;
	};

	struct MYT m;
	
	m.name = "Hong SungIl";
	m.age = 50;
	m.height = 181.1;

	puts(" < characters  >");
	printf(" name = %s \n", m.name);
	printf(" age = %d \n", m.age);
	printf(" height = %f \n", m.height);

	return 0;
}
	
