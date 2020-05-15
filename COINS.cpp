/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>

using namespace std;

bool f[1000006];
int n, k, l;

int main() {
    freopen("COINS.inp", "r", stdin);
    freopen("COINS.out", "w", stdout);
    scanf("%d%d%d", &k, &l, &n);
    for(int i=1; i<=1000000; ++i) {
        f[i] = !f[i-1];
        if (i >= k) f[i] = f[i] || (!f[i-k]);
        if (i >= l) f[i] = f[i] || (!f[i-l]);
    }
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        if (f[a]) cout << 'A';
        else cout << 'B';
    }
    return 0;
}
