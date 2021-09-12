//#include <stdio.h>
#include <iostream>
using namespace std

int main()
{

    char input[100];

    fgets(input, sizeof(input), stdin );

    while(1)
    {

    //fgets(input, sizeof(input), stdin );
	cin >> input;

    printf("%s\n", input);
    }

    return 0;
}
