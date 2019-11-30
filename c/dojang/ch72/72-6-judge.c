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

    FILE *fp = fopen("x850.bin", "wb");

    x1.serial = 32100;
    x1.mode = 'a';
    strcpy(x1.desc, "Hello, world!");
    x1.version = 2100000100;


	fwrite(&x1, sizeof(x1), 1, fp);
    fclose(fp);

    return 0;
}
