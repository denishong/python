#include <stdio.h>
#include <stdlib.h>

struct Point2D {
    int x;
    int y;
};


struct Point2D *allocPoint2D()
{
	struct Point2D *pos = malloc(sizeof(struct Point2D));

	pos->x = 90;
	pos->y = 75;

	return pos;
}
 
int main()
{
    struct Point2D *pos1;

    pos1 = allocPoint2D();

    printf("%d %d\n", pos1->x, pos1->y);

    free(pos1);

    return 0;
}
