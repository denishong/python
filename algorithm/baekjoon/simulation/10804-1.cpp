#include <iostream>
using namespace std;
int main(){
int a,b,v[21];
for(int i=0;i<20;i++)
v[i]=i+1;
for(int i=0;i<10; i++){
cin >> a >> b;
while(a<b){
swap(v[a-1],v[b-1]);
a++;b--;
}
}
for(int i=0; i<20; i++)
cout << v[i] << ' ';
return 0;
}
