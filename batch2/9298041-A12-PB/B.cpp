#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 21234;
const int inf = INT_MAX;

int c, n, m;
int fr[N], to[N], w[N], d[N];

int main() {
    scanf("%d",&c);
    while(c--) {
        memset(d,0,sizeof d);
        scanf("%d %d",&n, &m);
        for(int i = 0; i < m; i++) {
            int u, v, ww;
            scanf("%d %d %d",&u, &v, &ww);
            fr[i] = u; to[i] = v; w[i] = ww;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                d[to[j]] = min(d[to[j]], d[fr[j]] + w[j]);
        }
        int f = true;
        for(int i = 0; i < m && f; i++)
            if(d[to[i]] > d[fr[i]] + w[i]) {
                f = false;
                puts("possible");
            }

        if(f) puts("not possible");

    }
}

