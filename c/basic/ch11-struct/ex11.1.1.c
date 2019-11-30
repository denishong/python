#include <stdio.h>

int main()
{
	struct MYT{
		int age;
		float height;
	};

	struct MYT m;

	m.age = 50;
	m.height = 181.1;

	puts(" < age and height >");
	printf(" age = %d \n", m.age);
	printf(" height = %f \n", m.height);

	return 0;
}
	
