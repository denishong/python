#include <iostream>
using namespace std;
int main() {
    const int MAX_SIZE = 100001;
	int N,S;
	int min=(int)1e5;

    // 1 <= n <= 10,000
    cin >> N>>S;

    // 1 <= an[i] <= 30,000
    int an[MAX_SIZE];
    for (int i = 0; i < N; ++i) {
        cin >> an[i];
    }

    int count = 0;
    int start = 0, end = 0;
    long long sum = 0;
    while (start <= end ) {
        if (sum >= S) {
			if(min > (end-start))
                min=end-start;
				//cout<<"count:"<<count<<endl;
            sum -= an[start++];
        }
        else if(end==N)
			break;
		else
            sum += an[end++];
            //cout <<"start,end,sum,an[end++]:" <<start<<' '<<end<<' '<<sum<<' '<<an[end]<<endl;
    }
	if(min==(int)1e5)
		cout<<0<<endl;
	else
    	cout << min<< '\n';
    return 0;
}
