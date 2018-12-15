#include <stdio.h>

#define DOUBLEPOINT double *

int main(void)
{
    DOUBLEPOINT p, q;
	double * a;

    printf("%d", sizeof(p) + sizeof(q));
    printf("%d\n", sizeof(a));

    return 0;
}
