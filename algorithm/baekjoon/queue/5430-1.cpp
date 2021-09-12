/*baekjoon 5430 dequeue*/
#include <iostream>
#include <deque>
#include <cstring>
#include <stdlib.h>

using namespace std;
deque<int> q;
#define MAX 100 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int i=0,j=0,k=0,l,m;
    int testN; //test case
    int N; // N  
    int K; //K 
    char dt[MAX];
    char control[MAX];
    int numN= 0; 
    int numC, sizeq;
    int flag=true;
    int error=0;
    cin >> testN;


    for(i =0; i < testN; i++) {
        error = 0;
        cin >> control;
        cin >> N;
        cin >> dt;
        char *tok=strtok(dt, "[ , ]");

        flag = true;
        while(tok != NULL) {
            q.push_back(atoi(tok));
            tok=strtok(NULL, "[ , ]");
        }    

        numC = strlen(control);
        for(k=0; k< numC; k++ ) {
            if( control[k] == 'R') {
                flag =! flag;
            } else if (control[k] == 'D' ){
                if(!q.empty()){
                    if( flag == true )
                        q.pop_front();
                    else 
                        q.pop_back();
                } else{
                    error++ ;
                    continue;
                }
            }
        }

        if ( ! error) {
            cout << '[';
            sizeq = q.size();
            for(m=0; m<sizeq; m++){
                if( (flag == true) && !q.empty() ){
                    if( q.size() > 1){
                        cout << q.front() << ',';
                    }else{
                        cout << q.front();
                    }
                    if( !q.empty() ) { q.pop_front();}
                }else if( (flag == false) && !q.empty() ) {
                    if( q.size() > 1){
                        cout << q.back() << ',';
                    }else{
                        cout << q.back();
                    }
                   if(!q.empty()){ q.pop_back();}
                }
            }
            cout << ']' << endl;
        } else{
            cout << "error" << endl;
        }

    }

    return 0;
}
/*baekjoon 5430 dequeue*/
