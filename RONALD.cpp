/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool d[1006][1006], avail[1006];
vector<int> V[1006];
vector<vector<int> > connect;
int n, m;

void DFS(int u) {
    avail[u] = true;
    connect[connect.size()-1].push_back(u);
    for(int v: V[u])
    if (!avail[v]) DFS(v);
}

int main() {
    freopen("RONALD.inp", "r", stdin);
    freopen("RONALD.out", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        V[u].push_back(v);
        V[v].push_back(u);
        d[u][v] = d[v][u] = true;
    }
    for(int i=1; i<=n; ++i)
        if (!avail[i]) {
            connect.push_back(vector<int>(0, 0));
            DFS(i);
        }
    if (connect.size() <= 2) {
        for(vector<int> tmp : connect)
        for(int i=1; i<(int) tmp.size(); ++i)
        for(int j=0; j<i; ++j)
        if (!d[tmp[i]][tmp[j]]) {
            cout << "NO";
            return 0;
        }
        cout << "YES";
        return 0;
    } else {
        cout << "NO";
        return 0;
    }
    return 0;
}
