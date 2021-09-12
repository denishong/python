/*baekjoon 2751 수 정렬하기2 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000001

int main()
{
	int data[MAX];
	int i,j, N;
	int tmp, exchg;

	vector<int> v;

	//input data size
	cin >> N;

	//input data
	for(i=0; i<N; i++) {
		cin >> data[i];
		v.push_back(data[i]);
	}

	sort(v.begin(), v.end());
	for(vector<int>::iterator it=v.begin(); it<v.end(); it++)
		printf("%d\n", *it );
		
	return 0;
}
/*baekjoon 2751 수 정렬하기2 */
