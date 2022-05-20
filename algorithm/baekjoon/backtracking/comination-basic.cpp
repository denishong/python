#include<iostream>
 
#define MAX 4
using namespace std;
 
int Arr[MAX];
bool Select[MAX];
 
void Print()
{
    for (int i = 0; i < MAX; i++)
    {
        if (Select[i] == true)
        {
            cout << Arr[i] << " ";
        }
    }
    cout << endl;
 
}
 
void DFS(int Idx, int Cnt)
{
    if (Cnt == 3)
    {
        Print();
        return;
    }
 
    for (int i = Idx; i < MAX; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        cout << "before i, Cnt" << i << ',' << Cnt << endl;
        DFS(i, Cnt + 1);
        cout << "after i, Cnt" << i << ',' << Cnt << endl;
        Select[i] = false;
    }
}
 
int main(void)
{
    Arr[0] = 1;
    Arr[1] = 2;
    Arr[2] = 3;
    Arr[3] = 4;
    Arr[4] = 5;
 
    DFS(0, 0);
}
