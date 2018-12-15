#include <stdio.h>

int main(void){

	double num=3.14;
	double *ptr=&num;
	double **dptr=&ptr;
	double *ptr2;

	printf("%9p %9p \n", ptr, *dptr);
	printf("%9g %9g \n", num, *ptr);

return 0;
}
