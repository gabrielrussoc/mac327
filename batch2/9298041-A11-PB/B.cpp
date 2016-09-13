#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 11234;
const int M = 2e6 + 42;

int n, m, s, es, ss;
int to[M], nx[M], head[N], vis[M], deg[N];
int prox[M], res[M], ps;

void fail() {
    puts("0");
    exit(0);
}

int dfs(int u, int f, int s) {
    if(f && u == s) return true;
    vis[f] = 1;
    int ans = 0;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[e]) {
            deg[u]--;
            if(dfs(v,e,s)) return 1;
            if(deg[v]) dfs(v,0) 
        }
    }
    return 0;
}

int main() {
    es = 2;
    scanf("%d", &n);
    while(n--) {
        int u, v;
        scanf("%d",&m);
        scanf("%d", &u);
        s = u;
        for(int i = 0; i < m; i++) {
            scanf("%d",&v);
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            deg[u]++;
            un.insert(u);
            u = v;
        }
    }
    if(!dfs(s,0,s)) fail();
}
