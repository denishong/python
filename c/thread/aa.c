#include <stdio.h>

int main(void)
{

// utilities from Professor
   printf( "%c[2J", 27 );  // ESC sequence
   fflush( stdout );

return 0;
}

