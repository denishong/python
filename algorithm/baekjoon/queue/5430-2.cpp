/*baekjoon 5430 dequeue*/
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

deque<int> q;
#define MAX 100001 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int i=0,k=0,m;
    int testN; //test case
    char control[MAX]; //RD control 입력 
    int N; // dt array size    
    char dt[MAX*3+2];// array [1,2,3,4]
    int numC, sizeq;
    int flag;
    int error=0;
    cin >> testN;


    for(i =0; i < testN; i++) {
        error = 0;
        cin >> control;
        cin >> N;
        cin >> dt;
        char *tok=strtok(dt, "[,]");

        flag = 1;
        while(tok != NULL) {
            q.push_back(atoi(tok));
            tok=strtok(NULL, "[,]");
        }    

        numC = strlen(control);
        for(k=0; k< numC; k++ ) {
            if( control[k] == 'R') {
                flag = (flag + 1 )%2;
            } else if ( control[k] == 'D' ){
                if(!q.empty()){
                    if( flag == true ){
                        q.pop_front();
                    }else if( flag == false){
                        q.pop_back();
                    }
                } else{
                    error++ ;
                    continue;
                }
            }
        }

        if (!q.empty() &&  error == 0) {
            cout << '[';
            sizeq = q.size();
            for(m=0; m<sizeq; m++){
                if( !q.empty() && (flag == true) ){
                    if( q.size() > 1){
                        cout << q.front() << ',';
                    }else if(q.size() == 1) {
                        cout << q.front();
                    }
                     q.pop_front();
                }else if( !q.empty() && (flag == false) ) {
                    if( q.size() > 1){
                        cout << q.back() << ',';
                    }else if( q.size() == 1) {
                        cout << q.back();
                    }
                    q.pop_back();
                }
            }
            cout << ']' << '\n';
        } else if(error >= 1){
            cout << "error" << '\n';
        }else if(q.size()==0){
            cout <<  "[]\n";
        }

    }

    return 0;
}
/*baekjoon 5430 dequeue*/
