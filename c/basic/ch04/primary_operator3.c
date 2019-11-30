#include <stdio.h>

int main()
{
	struct MYT{
		int age;
		int height;
		float weight;
	};

	struct MYT hsi;
	struct MYT *t;
	t = &hsi;

	t->age = 22;
	t->height =43;
	t->weight = 74.4;

	printf("%d\n", hsi.age);
	printf("%d\n", hsi.height);
	printf("%f\n", hsi.weight);

}

