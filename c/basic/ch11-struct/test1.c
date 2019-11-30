#include <stdio.h>

struct results{
	char credit;
	int grade;
};


void print_card(struct results)
{

	puts(" < school test results >");
	printf(" credit = %c \n", m.credit);
	printf(" grade = %d \n", m.grade);
	printf(" m struct size is  %ld \n", sizeof(m));
}

int main()
{
	struct results m;

	m.credit = 'A';
	m.grade = 81;

	puts(" < school test results >");
	printf(" credit = %c \n", m.credit);
	printf(" grade = %d \n", m.grade);
	printf(" m struct size is  %ld \n", sizeof(m));

	return 0;
}
	
