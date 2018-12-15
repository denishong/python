#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch, i;
	FILE * fp=fopen("data.txt", "rt");
	if(fp==NULL){
		puts("failed to open file");
		return -1;
	}

//	for(i=0; i<3; i++)
	{
		//ch=fgetc(fp);
		fscanf(fp, "%d", &ch);
		printf("%c \n", ch);
		printf("%d \n", atoi((int*)ch));
	}

	fclose(fp);
	return 0;
}
 
