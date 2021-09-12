#include <stdio.h>

#define Size 8

int main()
{
    int i,j,x,y, count = 0;
	char BW[Size][Size];
	char WB[Size][Size];
    char chess[51][51];

/*input chess colum, row size */
    scanf("%d %d", &x, &y);

/*BW pattern chess */
	for(i=0; i<Size; i++)
		for(j=0; j<Size; j++)
			if((i+j)%2 ==0)
				BW[i][j] = 'B';
			else
				BW[i][j] = 'W';

/*WB pattern chess */
	for(i=0; i<Size; i++)
		for(j=0; j<Size; j++)
			if((i+j)%2 ==0)
				WB[i][j] = 'W';
			else
				WB[i][j] = 'B';

/*input chess pattern in according to xy */
    for(i=0; i<x; i++)
		scanf("%s", chess[i]);

	if( chess[0][0] == 'W' ){
    	for(i=0; i<x; i++)
        	for(j=0; j<y; j++)
				if(chess[i][j] != WB[i][j]){
					count++;
				}

	}else if( chess[0][0] == 'B' ){
    	for(i=0; i<x; i++)
        	for(j=0; j<y; j++)
				if(chess[i][j] =! BW[i][j]){
					count++;
				}
	}


	printf("%d", count);

    return 0;
}
