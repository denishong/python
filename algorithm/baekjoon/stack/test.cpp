#include <iostream>

using namespace std;

int main()
{

	cout << "hello";

	char input[200];

	while(1)
	{
		if( input[0] == '.' )
			break;

		cin >> input;

		printf("%s", input);
	}

	return 0;
}
