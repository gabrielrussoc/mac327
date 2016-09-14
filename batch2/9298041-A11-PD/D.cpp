#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 501;

int q[N], app[N];
ll ans[N];
int m[N][N];
int d[N][N];
int inf = 123456789;
int n;

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%d",&m[i][j]);
        }

    for(int i = 0; i < n; i++) scanf("%d",q+i);
    for(int i = n-1; i+1; i--) {
        ll res = 0;
        int x = q[i]-1;
        app[x] = 1;
        for(int u = 0; u < n; u++) {
            d[u][x] = m[u][x];
            d[x][u] = m[x][u];
        }

        for(int u = 0; u < n; u++)
            for(int v = 0; v < n; v++) {
                if(!app[u] || !app[v]) continue;
                d[u][x] = min(d[u][x], d[u][v] + d[v][x]);
                d[x][u] = min(d[x][u], d[x][v] + d[v][u]);
            }
    
        for(int u = 0; u < n; u++)
            for(int v = 0; v < n; v++) {
                if(!app[u] || !app[v]) continue;
                d[u][v] = min(d[u][v], d[u][x] + d[x][v]);
                res  += ll(d[u][v]);
            }
        ans[i] = res;
    }
    for(int i = 0; i < n; i++) printf("%lld%c",ans[i]," \n"[i==n-1]);
}

