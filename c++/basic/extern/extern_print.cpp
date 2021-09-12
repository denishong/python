#include <iostream>
#include "extern.h"
using namespace std;


int print_num(void){
	cout << "this is extern_print.cpp" << endl;
	for(int i=0; i<10; i++)
		cout << num1++ << endl;
	return num1;
}
