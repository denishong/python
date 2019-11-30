#include <stdio.h>

int main()
{
	struct MYT{
		char *name;
		int age;
		float height;
	};

	struct MYT m ={"Hong SungIl", 76, 181.1};
	struct MYT n ={"Song Soyeon", 50, 159.9};
	

	puts(" < characters  >");
	printf(" %10s%10s%10s\n", "name","age","height");
	printf(" %10s%10d%10.1f\n", m.name, m.age, m.height); 
	printf(" %10s%10d%10.1f\n", n.name, n.age, n.height); 

	return 0;
}
	
