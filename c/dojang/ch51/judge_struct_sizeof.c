#include <stdio.h>

struct EncryptionHeader {
    char flags;
	int a;
	int b;
};
 
int main()
{
    struct EncryptionHeader header;
 
    printf("%d\n", sizeof(header));

    return 0;
}
