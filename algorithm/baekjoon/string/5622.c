#include <stdio.h>

int main()
{

	int sum=0,i=0;
	char dial[16], ch;

	scanf("%s",dial );


	while( dial[i] != '\0' )
	{
		ch = dial[i];

		if( ch == 'A' || ch == 'B' || ch == 'C')
			sum += 3;
		else if( ch == 'D' || ch == 'E' || ch == 'F')
			sum += 4;
		else if( ch == 'G' || ch == 'H' || ch == 'I')
			sum += 5;
		else if( ch == 'J' || ch == 'K' || ch == 'L')
			sum += 6;
		else if( ch == 'M' || ch == 'N' || ch == 'O')
			sum += 7;
		else if( ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S')
			sum += 8;
		else if( ch == 'T' || ch == 'U' || ch == 'V')
			sum += 9;
		else if( ch == 'W' || ch == 'X' || ch == 'Y' || ch =='Z')
			sum += 10;

		//printf("dial : %c \n", dial[i]);
		i++;
	}
	printf("%d\n", sum);

	return 0;
}
