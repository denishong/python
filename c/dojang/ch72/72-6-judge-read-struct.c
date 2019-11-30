#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
struct X820Firmware {
    short serial;
    char mode;
    char desc[20];
    int version;
};
#pragma pack(pop)
 
int main()
{
    struct X820Firmware x1;
    memset(&x1, 0, sizeof(x1));

    FILE *fp = fopen("x850.bin", "rb");


	fread(&x1, sizeof(x1), 1, fp);
	printf("%d\n", x1.serial);
	printf("%c\n", x1.mode);
	printf("%s\n", x1.desc);
	printf("%d\n", x1.version);
    fclose(fp);

    return 0;
}
