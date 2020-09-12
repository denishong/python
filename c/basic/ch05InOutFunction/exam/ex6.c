#include <stdio.h>
#include <string.h>

int main()
{
	char *ch;
	printf("__STDC_VERSION__:%ld", __STDC_VERSION__);
	printf("Name?");
	fgets( ch, 12, stdin );

	ch[strcspn(ch, "\n")] = 0;
	//printf("%s\n", ch);
	puts( ch );
	return 0;
}
