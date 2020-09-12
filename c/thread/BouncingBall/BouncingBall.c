/**************************************
 * Subject : [ECE321] Operating System
 * Class # : 1
 *
 * Author  : Hong, Charm Gil / CSEE
 * Student#: 20200636
 *
 * Creation Date: 18 May 2007
 * Completion Date: 22 May 2007
 **************************************/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

typedef struct{
	short ballNumber, x, y, hDir, vDir, delay_time;
} ballInfoBlock;

//global variables
pthread_mutex_t mutex_printxy;
short do_loop = 1;
char _BLANK[ 2 ] = " ";
	
// utilities from Professor
void clrscr( void ){
	printf( "%c[2J", 27 );	// ESC sequence
	fflush( stdout );
}

void gotoXY( int x, int y ){
	printf( "%c[%d;%df", 27, y, x );
	fflush( stdout );
}

void printXY( int x, int y, char *format, ... ){
	va_list vl;
	pthread_mutex_lock( &mutex_printxy );	//lock mutex variable
	
	printf( "%c[%d;%df", 27, y, x );
	
	va_start( vl, format );
	vprintf( format, vl );
	va_end( vl );
	
	printf( "%c[%d;%df", 27, 24, 23 );	// move cursor to lower left corner
	fflush( stdout );
	pthread_mutex_unlock( &mutex_printxy );	//release mutex variable
}

void delay( clock_t msec ){
	clock_t finish;
	finish = clock() + ( msec * CLOCKS_PER_SEC / 1000 );
	while( finish > clock() );
}


// thread definition
void *runner( void *param ){
	ballInfoBlock ball = *( ballInfoBlock* )param;
	
	// ball movement
	while( do_loop ){
		printXY( ball.x, ball.y, "%d", ball.ballNumber );		// print ball
		printXY( ball.x - ball.hDir, ball.y - ball.vDir, _BLANK );	// erase previous ball
		delay( ball.delay_time );		// note that, if you change the order of print-erase-delay-move to erase-print-delay-move, you may see better screen refresh(no afterimage)
		
		//direction check
		if( 2 == ball.x || 79 == ball.x )	ball.hDir *= -1;
		if( 2 == ball.y || 22 == ball.y )	ball.vDir *= -1;
		//move
		ball.x += ball.hDir;
		ball.y += ball.vDir;
	}
	pthread_exit( 0 );
}

// main function - getting user input and generating threads
int main( int argc, char *argv[] ){
	pthread_t tid[ 10 ];
	ballInfoBlock param[ 10 ];
	short i;
	
	// exceptional input handling
	if( argc < 2 || 0 > atoi( argv[ 1 ] ) || 10 < atoi( argv[ 1 ] ) ){
		( argc < 2 ) ? fprintf( stderr, "usage: a.out <integer>\n" )
								: fprintf( stderr, "error: input integer should be between 0 and 10\n" );
		exit( 0 );
	}

	// initialize
	pthread_mutex_init( &mutex_printxy, NULL );		//initialize mutex
	srand( time( NULL ) );	// shuffle random table
	// initialize screen - drawing frame
	clrscr();
	for( i = 1 ; i <= 79 ; i++ ){
		if( i <= 23 ) printXY( 1, i, "#" );
		if( i <= 23 ) printXY( 80, i, "#" );
		printXY( i, 1, "#" );
		printXY( i, 23, "#" );
	}
	printXY( 1, 24, "Press [enter] to quit " );
	
	// generating threads
	for( i = 0 ; i < atoi( argv[ 1 ] ) ; i++ ){
		param[ i ].ballNumber = i;	//ball number assigning
		param[ i ].delay_time = rand() % 101;	//randomly assigning delay between movement
		param[ i ].x = rand() % 78 + 2;		//randomly assigning start point
		param[ i ].y = rand() % 21 + 2;
		( param[ i ].x == 2 ) ? ( param[ i ].hDir = -1 ) : ( ( param[ i ].x == 79 ) ? ( param[ i ].hDir = 1 ) : ( param[ i ].hDir = ( rand() % 2 ) * 2 - 1 ) );		// randomly assigning horizontal/vertical direction value
		( param[ i ].y == 2 ) ? ( param[ i ].vDir = -1 ) : ( ( param[ i ].y == 22 ) ? ( param[ i ].vDir = 1 ) : ( param[ i ].vDir = ( rand() % 2 ) * 2 - 1 ) );		// to avoid err, for assigned value x = 2, x = 79, y = 2, y = 22, clearly assign 1 or -1
		
		pthread_create( &tid[ i ], NULL, runner, ( void* )&param[ i ] );	//create a thread
	}
	
	while( getchar() != 10 );
	do_loop = 0;
	for( i = 0 ; i < atoi( argv[ 1 ] ) ; i++ )
		pthread_join( tid[ i ], NULL );
	
	gotoXY( 1, 24 );	// move cursor to (1, 24) in order to make sure print out "Goodbye!\n" at correct location
	printf( "\nGoodbye!\n" );
	
	return 0;
}	// end of main
