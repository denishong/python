#include <stdio.h>

int main(void)
{
	int ch, i;
	FILE * fp=fopen("simple.txt", "wt");
	if(fp==NULL){
		puts("failed to open file");
		return -1;
	}

	fputc('A',fp);
	fputc('B',fp);
	fputs("My name is Hong \n",fp);
	fputs("Your name is Yoon\n",fp);

	fclose(fp);
	return 0;
}
 
