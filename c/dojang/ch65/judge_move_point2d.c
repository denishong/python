#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point2D {
    int x;
    int y;
};

void movePoint2D(struct Point2D *p1, int offsetX, int offsetY)
{
	p1->x += offsetX;
	p1->y += offsetY; 

} 


int main()
{
    struct Point2D p1;
    int offsetX, offsetY;
 
    scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

    movePoint2D(&p1, offsetX, offsetY);

    printf("%d %d\n", p1.x, p1.y);

    return 0;
}
