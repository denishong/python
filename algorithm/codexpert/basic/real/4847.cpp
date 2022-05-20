#include <iostream>
using namespace std;

struct Coord{
    int r;
    int c;
};

Coord pos[5*5+10];
int A[5+10][5+10];
int B[25+10];

void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}

int Check(int k){
    int i;
    int vr =pos[k].r, vc = pos[k].c;
    int cnt =0; //완성된 줄 개수 
    
    A[vr][vc] = 0;

    //1.가로 완성 확인 
    for( i=0; i<5; i++){
        if(A[vr][i]!=0) break;
    }
    if(i==5){ cnt++;
        //cout << "cnt : " << cnt << __LINE__<< endl;
    }
    //2.세로  완성 확인 
    for( i=0; i<5; i++){
        if(A[i][vc]!=0) break;
    }
    if(i==5){ cnt++;
        //cout << "cnt : " << cnt << __LINE__<< endl;
    }

    //3.좌상단 완성 확인 
    if(vc == vr){
        for( i=0; i<5; i++){
            if(A[i][i]!= 0) break;
        } 
        if(i==5){ cnt++;
        //cout << "cnt : " << cnt << __LINE__<< endl;
        }
    }

    //4.우상단 완성 확인 
    if(vr+vc==4){
        for( i=0; i<5; i++){
            if(A[i][4-i]!=0) break;
        }
        if(i==5){ cnt++;
        //cout << "cnt : " << cnt << __LINE__<< endl;
        }
    }

    return cnt;
}

void Print(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int Solve(){
    int k, bingo=0;
    for( int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            k = A[i][j];
            pos[k].r=i; pos[k].c=j;
        }
    }

    for(k=0; k<5*5; k++){
        bingo += Check(B[k]);
        if( bingo >=3 ) break;
    }
    return k+1;
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}
