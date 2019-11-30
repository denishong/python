#include <pthread.h>
#include <stdio.h>
#include <stdarg.h>

//global variables
pthread_mutex_t mutex_printxy;
short do_loop = 1;
char _BLANK[ 2 ] = " ";

// utilities from Professor
void clrscr( void ){
   printf( "%c[2J", 27 );  // ESC sequence
   fflush( stdout );
}

void printXY( int x, int y, char *format, ... ){
   va_list vl;
   pthread_mutex_lock( &mutex_printxy );  //lock mutex variable

   printf( "%c[%d;%df", 27, y, x );

   va_start( vl, format );
   vprintf( format, vl );
   va_end( vl );

   printf( "%c[%d;%df", 27, 24, 23 );  // move cursor to lower left corner
   fflush( stdout );
   pthread_mutex_unlock( &mutex_printxy );   //release mutex variable
}

int main(void)
{
int i;
//clrscr();

for( i = 1 ; i <= 79 ; i++ ){
      if( i <= 23 ) printXY( 1, i, "#" );
      if( i <= 23 ) printXY( 80, i, "#" );
      printXY( i, 1, "#" );
      printXY( i, 23, "#" );
   }   

return 0;
}
