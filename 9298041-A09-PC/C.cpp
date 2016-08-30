#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

void fail() {
    puts("NO");
    exit(0);
}

const int N = 10007;
vector<int> adj[N];
int vis[N], n, m;

void dfs(int u, int p) {
    if(vis[u]) fail();
    vis[u] = 1;
    for(int v : adj[u])
        if(v != p) dfs(v, u);
}

int main() {
    scanf("%d %d", &n, &m);
    if(m != n-1) fail();
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u,&v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0,0);
    for(int i = 0; i < n; i++) if(!vis[i]) fail();
    puts("YES");
}

