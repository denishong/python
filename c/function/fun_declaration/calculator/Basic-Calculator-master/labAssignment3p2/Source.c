#include <stdio.h>


float num1, num2;
char calc;

int main() {
	printf("Please use the following for calculations\n");
	printf("A - additions \n S - subtraction \n M - multiplication \n D - division \n");
	
	printf("Please enter letter for calculation: \n");
	scanf("%c", &calc);

	printf("Please enter you numbers: \n");
	scanf("%f %f", &num1, &num2);

	

	switch (calc) {
	case 'A':
		printf("%f + %f = %f", num1, num2, num1 + num2 );
			break;
	case 'S':
		printf("%f - %f = %f", num1, num2, num1 - num2);
			break;
	case 'M':
		printf("%f * %f = %f", num1, num2, num1 * num2);
		break;
	case 'D':
		printf("%f / %f = %f", num1, num2, num1 / num2);
		break;
	default:
		printf("-9999");

	}
	int exit;
	scanf("%d", &exit);
	printf("Exit %d", exit);
}