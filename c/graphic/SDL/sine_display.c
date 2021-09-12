#include <graphics.h>
#include <stdio.h>
#define ROUND(a) ((int) (a+0.5))
#include <X11/Xlib.h>


int main(int argc, char* argv[])
{
    int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,radius=50;
	int angle = 0;
	double x, y;

    initgraph(&gd,&gm,NULL);
    line(0, getmaxy()/2, getmaxx(), getmaxy() / 2);
	printf("maxx : %d, maxy : %d \n", getmaxx(), getmaxy());

 for(x = 0; x < getmaxx(); x+=3) {
 
     /* calculate y value given x */
     y = 50*sin(angle*3.141/180);
     y = getmaxy()/2 - y;
 
     /* color a pixel at the given position */
  putpixel(x, y, 15);
  delay(10);
 
  /* increment angle */
  angle+=7;
 }
 
	getch();
    closegraph();
    return 0;
}
