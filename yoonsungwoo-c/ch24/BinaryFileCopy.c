#include <stdio.h>

int main(void)
{
	FILE * src=fopen("src.bin", "rb");
	FILE * des=fopen("det.bin", "wb");
	
	char buf[512];
	int readCnt;

	if(src==NULL || des==NULL){
		puts("file open fail!!");
		return -1;
	}

	while(1)
	{
		readCnt=fread((void*)buf, 1, sizeof(buf),src);
		printf("readCnt : %d\n", readCnt);
		if(readCnt<sizeof(buf))
		{
			if(feof(src)!=0)
			{
				fwrite((void*)buf,1,readCnt,des);
				puts("file copy complete");
				break;
			}
			else
				puts("file copy fail");

			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);
	return 0;
}
