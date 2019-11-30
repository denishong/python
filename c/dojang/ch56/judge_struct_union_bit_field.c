#include <stdio.h>

struct Flags {
    union {
        struct {
			unsigned short a : 3;
			unsigned short b : 4;
			unsigned short c : 7;
			unsigned short d : 2;
        };
        unsigned short e;
    };
};
 
int main()
{
    struct Flags f1 = { 0, };
 
    f1.a = 4;
    f1.b = 8;
    f1.c = 64;
    f1.d = 3;

    printf("%u\n", f1.e);

    return 0;
}
