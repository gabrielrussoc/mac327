#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 11234;
const int M = 2e6 + 42;

int n, m, s, es;
int to[M], nx[M], head[N], vis[M], deg[N];
vector<int> ans;

void fail() {
    puts("0");
    exit(0);
}

int dfs(int u, int f, int s) {
    vis[f] = 1;
    if(f && u == s) return true;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[e]) {
            deg[u]--;
            if(dfs(v,e,s)) {
                while (deg[v])
                    if (!dfs(v,0,v)) return 0;
                ans.pb(v);
                return 1;
            }
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
            u = v;
        }
    }
    if(dfs(s,0,s)) while(deg[s]) if (!dfs(s,0,s)) fail();
    printf("%d",ans.size());
    ans.pb(ans[0]);
    reverse(ans.begin(), ans.end());
    for(int u : ans) printf(" %d",u);
    putchar('\n');
}
