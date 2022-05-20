#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[6] = { 10,11,13,14,25,26 };
	cout << "lower_bound(14) : " << lower_bound(arr, arr + 6, 14)-arr;
	cout << "upper_bound(14) : " << upper_bound(arr, arr + 6, 14)-arr;

	return 0;
}
