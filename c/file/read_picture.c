#include <stdio.h>
//#include <highgui.h>
#include <cvdef.h>


int main( int argc, char** argv ) {

IplImage* img = 0;
IplImage* out = 0;

if( argc < 2 ) {
    printf( "Usage: Accepts one image as argument\n" );
    exit( EXIT_SUCCESS );
}

img = cvLoadImage( argv[1] );

if( !img ) {
    printf( "Error loading image file %s\n", argv[1]);
    exit( EXIT_SUCCESS );
}

out = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 3 );


cvSmooth( img, out, CV_GAUSSIAN, 3, 3 );

cvReleaseImage( &img );
cvReleaseImage( &out );
cvDestroyWindow( "Example1" );
cvDestroyWindow( "Output" );
return EXIT_SUCCESS;
}
