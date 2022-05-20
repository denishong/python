#include<iostream>
#include<vector>
 
#define endl "\n"
#define MAX 9
using namespace std;
 
int N, M;
bool Visit[MAX];
vector<int> V;
 
void Input()
{
    cin >> N >> M;
}
 
void DFS(int Cnt)
{
    if (Cnt == M)
    {
        for (int i = 0; i < V.size(); i++)
        {
            cout << V[i] << " ";
        }
        cout << endl;
        return;
    }
 
    for (int i = 1; i <= N; i++)
    {
        if (Visit[i] == true) continue;
        Visit[i] = true;
        V.push_back(i);
        DFS(Cnt + 1);
        Visit[i] = false;
        V.pop_back();
    }
}
 
void Solution()
{
    DFS(0);
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
