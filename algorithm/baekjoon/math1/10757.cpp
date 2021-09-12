#include <iostream>

using namespace std;
int c2d[128];
char d2c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char S[101],D[101]; // input number
int B = 10;

void inputData(){
	cin >> S >> D;
}

void makec2d(){

	int i,j;
	for(i='0', j=0; i<='9'; i++,j++){
		c2d[i]=j;
	}

	for(i='A'; i<='Z'; i++,j++){
		c2d[i]=j;
	}

}

int conv( int *dst, char *src){
	int i;
	for( i =0; src[i]; i++) dst[i] = c2d[src[i]];
	return i;
}

void mul(char *s, char *d){
	int S[110], D[110], sol[210]={0};
	int slen = conv(S,s);
	int dlen = conv(D,d);
	int len = slen + dlen, i,j;

	for( i = 0; i < slen; i++){
		for( j = 0; j < dlen; j++){
			sol[i + j + 1] += S[i] * D[j];
		}
	}

	for( i = len - 1; i > 0; i--){
		if( sol[i] >= B){
			sol[i - 1] += sol[i] / B;
			sol[i] %= B;
		}
	}


	for( i= sol[0] == 0; i< len; i++){
		cout << d2c[sol[i]];
	}
	cout << '\n';

}

void add(char *s, char *d){
	int S[110], D[110], sol[210]={0};
	int slen = conv(S,s);
	int dlen = conv(D,d);
	int len = slen + dlen, i,j;

	for( i = 0; i < slen; i++){
		for( j = 0; j < dlen; j++){
			sol[i + j + 1] += S[i] * D[j];
		}
	}

	for( i = len - 1; i > 0; i--){
		if( sol[i] >= B){
			sol[i - 1] += sol[i] / B;
			sol[i] %= B;
		}
	}


	for( i= sol[0] == 0; i< len; i++){
		cout << d2c[sol[i]];
	}
	cout << '\n';

}

void solve(){

	char *s = S, *d = D;

	add( s, d);
}


int main(){

	makec2d();
	inputData();
	solve();

	return 0;
}
