#include <highgui.h>

int main()
{

	IplImag *image = cvLocadImage("");
	cvShowImage("Test",image);
	cvWaitKey(0);
	cvReleaseImage(&image);

	return 0;
}
