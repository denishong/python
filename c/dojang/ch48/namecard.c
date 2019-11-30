#include <stdio.h>

struct card{
	char *name;
	char *corp;
	int phone;
};

int main()
{
	struct card d1;
	
	d1.name = "denis hong";
	d1.corp = "lge";

	printf("d1.name : %s\n", (char *)d1.name);
	printf("d1.corp : %s\n", (char *)d1.corp);

	return 0;
}
