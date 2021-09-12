#include <iostream>
#include <streambuf>
using namespace std;
 
int main()
{
	istringstream in("1234567890123456789");
    int w(0);
    for (int value(0); in >> fw(++w) >> value; ) {
        std::cout << "value=" << value << "\n";
    } 
	return 0;
}
