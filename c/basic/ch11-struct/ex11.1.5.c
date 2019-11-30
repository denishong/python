#include <stdio.h>

int main()
{
	typedef struct MYT{
		char *name;
		int age;
		float height;
	}aa;

	aa m ={"Hong SungIl", 60, 181.1};
	//struct aa m ={"Hong SungIl", 60, 181.1};
	

	puts(" < characters  >");
	printf(" name = %s \n", m.name);
	printf(" age = %d \n", m.age);
	printf(" height = %f \n", m.height);

	return 0;
}
	
