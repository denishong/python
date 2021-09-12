#include <stdio.h>

int main()
{
    int H,M;
    scanf("%d %d", &H, &M);

	if( (1 <= H) && (H <=23) )
	{
		if( M >= 45){
			M -= 45;
		} else if (M <45){
			H -= 1;
			M += (60-45);
		}
	} else if( H == 0){
		if( M >= 45){
			M -= 45;
		} else if (M <45){
			H = 23;
			M +=(60-45);
		}
	}

    printf("%d %d\n",H,M);
    return 0;
}
