#include <stdio.h>


int main()
{

	FILE *fp;
	
	fp = fopen("test.txt", "r");

	if(fp == NULL)
	{
		printf("file open fail!!\n");
		return 0;
	}

	return 0;
}
