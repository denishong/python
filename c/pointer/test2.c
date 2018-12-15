#include <stdio.h>

char* myname(){

	char* myname="denis hong";
	return myname;
}
int main(){

	printf("pointer test\n");

	printf("my name is %s.\n",myname());

	return 0;

}
