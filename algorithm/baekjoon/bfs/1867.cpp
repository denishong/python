#include <bits/stdc++.h>
using namespace std;
struct info{
    int conn,to;
    long long val;
};
info tmp;
int N,to;
char c;
long long val;
long long result=0;
info arr[130000];
void Solve(){
    queue<int>q;
    for(int i=2; i<=N; i++){
        if(arr[i].conn==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur=q.front(); q.pop();
        int next=arr[cur].to;
        long long cv=arr[cur].val;
        if(cv>0) arr[next].val+=cv;
        arr[next].conn--;
        if(arr[next].conn==0) q.push(next);
    }
    cout<<arr[1].val;
}
void InputData(){
    cin>>N;        
    for(int i=2; i<=N; i++){
        cin>>c>>val>>to;
        if(c=='W') val=-val;
        arr[i].to=to;
        arr[i].val=val;
        arr[to].conn++;
    }
}
int main(){
    InputData();
    Solve();
    return 0;
}
