#include <iostream>
#include <queue>
using namespace std;
#define MAXN ((int) 1e2)
string c;
string tmp;
string outstring;
queue <char> q;
int cnt;
void InputData(void){
    cin >> c;
}
void PushData(){
    char k;
    string tmpC;
    for(int i=0; i<tmp.size(); i++){
        if( tmp[i] >= '1' && tmp[i] <= '9'){
            k = tmp[i];
        } else {
            tmpC += tmp[i];
        }
    }
   
  //  cout << "tmpC, k : Line " << tmpC << ',' <<  k << ':' <<   __LINE__ << endl;
    if(k !=0){
        for(int i=0; i<k-'0'; i++){
           outstring += tmpC;
        }
    }else{
      outstring += tmpC;
    }
}
void OutputData(){
    char k;
    string tmpC;
    for(int i=0; i<outstring.size(); i++){
        if( outstring[i] >= '1' && outstring[i] <= '9'){
            k = outstring[i];
        } else {
            tmpC += outstring[i];
        }
    }
   
    //cout << "tmpC, k : Line " << tmpC << ',' <<  k << ':' <<   __LINE__ << endl;
    for(int i=0; i<k-'0'; i++){
      cout << tmpC;
    }
}
void Solve(){
    int depth=0,check=0;
    for(int i =0; c[i]; i++){
        if (c[i] == '<' ){
            depth++;
            check++;
 //   cout << "tmp, depth : Line " << tmp << ',' <<  depth  << ':' <<   __LINE__ << endl;
            if( tmp != "" && depth >=2 ){
                outstring += tmp;
            }else if( tmp != "" && depth >=2 ){
                PushData();
                //cout << "outstring : " << outstring << __LINE__ << endl;
            }
         tmp = "";
        } else if( c[i] == '>' ) {
            depth--; 
            check++;
//    cout << "tmp, depth, check : Line " << tmp << ',' <<  depth << ',' << check  << ':' <<   __LINE__ << endl;
            if( tmp != "" && depth >=1){
                PushData();
            }
            if( depth==0 && check == 2){
                outstring += tmp;
                OutputData();
            } else if( depth==0){
                PushData();
                OutputData();
            }
                tmp = "";
        } else {
            tmp += c[i];
        }
    }
}
int main(void){
    InputData();
    Solve();
    return 0;
}
