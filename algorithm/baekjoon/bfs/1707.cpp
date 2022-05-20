#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int) 2e4)
int K; //test case
vector<int> connection[MAXN+10];
int colored[MAXN+10];

void dfs(int v, int color)
{
    colored[v] = color;
    for (int i = 0; i < connection[v].size(); i++) {
        int to = connection[v][i];
        if (!colored[to]) {
            dfs(to, 3 - color);
        }
    }
}
bool check_color(int v_len)
{
    for (int i = 1; i <= v_len; i++) {
        for (int j = 0; j < connection[i].size(); j++) {
            int nxt = connection[i][j];
            if (colored[i] == colored[nxt])
                return false;
        }
    }
    return true;
}
void Solve()
{
    int V, E;
    while (K--) {
        cin >> V >> E;
        for (int i = 0; i <= V; i++) {
            connection[i].clear();
            colored[i] = 0;
        }

        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            connection[a].push_back(b);
            connection[b].push_back(a);
        }

        for (int i = 1; i <= V; i++) {
            if (!colored[i])
                dfs(i, 1);
        }

        if (check_color(V))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
void InputData(){
    cin >> K;
}
int main(){
    InputData();
    Solve();
    return 0;
}
