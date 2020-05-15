/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define llong long long

using namespace std;

vector<pair<int, int> > V[100006];
bool inQueue[100006][6];
llong d[100006][6];
int n, m, k, s, t;
queue<pair<int, int> > Q;

void push(pair<int, int> v) {
    if (!inQueue[v.first][v.second]) {
        inQueue[v.first][v.second] = true;
        Q.push(v);
    }
}

void BFS() {
    for(int i=1; i<=n; ++i)
    for(int j=0; j<=k; ++j) d[i][j] = 1e18;
    d[s][0] = 0; inQueue[s][0] = true;
    Q.push(make_pair(s, 0));
    do {
        pair<int, int> u = Q.front(); Q.pop();
        inQueue[u.first][u.second] = false;
        for(pair<int, int> e: V[u.first]) {
            pair<int, int> v = make_pair(e.first, u.second);
            if (d[v.first][v.second] > d[u.first][u.second] + e.second) {
                d[v.first][v.second] = d[u.first][u.second] + e.second;
                push(v);
            }
            if (u.second < k) {
                v = make_pair(e.first, u.second+1);
                if (d[v.first][v.second] > d[u.first][u.second]) {
                    d[v.first][v.second] = d[u.first][u.second];
                    push(v);
                }
            }
        }
    } while (!Q.empty());
}

int main() {
    freopen("FREEBUS.inp", "r", stdin);
    freopen("FREEBUS.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    for(int i=1; i<=m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        V[u].push_back(make_pair(v, w));
        V[v].push_back(make_pair(u, w));
    }
    BFS();
    cout << *min_element(d[t], d[t]+k+1);
    return 0;
}
