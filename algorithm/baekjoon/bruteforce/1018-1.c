#include <stdio.h>

#define Size 8

int main()
{
    int i,j,x,y, count = 0, count_min=64;
	int k,r;
	char BW[Size][Size];
	char WB[Size][Size];
    char chess[50][50] = {0, };

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
    	for(i=0; i<=x-8; i++){
        	for(j=0; j<=y-8; j++){
				count = 0;
				for(k=0; k<8; k++){
					for(r=0; r<8; r++){
						if(chess[i+k][j+r] != WB[k][r]){
							count++;
						}
					}
				}
			if( count < count_min ) count_min = count;
			}
		}
	}else if( chess[0][0] == 'B' ){
    	for(i=0; i<=x-8; i++){
        	for(j=0; j<=y-8; j++){
				count = 0;
				for(k=0; k<8; k++){
					for(r=0; r<8; r++){
						if(chess[i+k][j+r] != BW[k][r]){
							count++;
						}
					}
				}
			if( count < count_min ) count_min = count;
			}
		}
	}


	printf("%d", count_min);

    return 0;
}
