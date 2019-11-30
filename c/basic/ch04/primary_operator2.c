#include <stdio.h>

int main()
{
	struct MYT{
		int age;
		int height;
		int weight;
	};

	struct MYT hsi;
	hsi.age = 20;
	hsi.height =40;
	hsi.weight = 74;

	printf("%d\n", hsi.age);
	printf("%d\n", hsi.height);
	printf("%d\n", hsi.weight);

}

