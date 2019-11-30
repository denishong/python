#include <stdio.h>

#pragma pack(push, 1)
struct EncryptionHeader {
    char flags;
	short b;
};
#pragma pack(pop)
 
int main()
{
    struct EncryptionHeader header;
 
    printf("%d\n", sizeof(header));

    return 0;
}
