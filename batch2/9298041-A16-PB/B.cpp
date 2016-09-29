#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1e3+7;
const int inf = INT_MAX;
int to[N], head[N], cap[N], nx[N], fl[N], vis[N], ans[N];
int n, es, turn, s, t, m;

int dfs(int u, int mini) {
    vis[u] = turn;
    if(u == t) return mini;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(vis[v] != turn && cap[e]-fl[e]) {
            int k = dfs(v, min(mini, cap[e]-fl[e]));
            if(k != inf) {
                fl[e] += k;
                fl[e^1] -= k;
                return k;
            }
        }
    }
    return inf;
}

void dfsa(int u) {
    ans[u] = 1;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!ans[v] && cap[e]-fl[e])
            dfsa(v);
    }
}

int maxflow() {
    int mf = 0, k;
    memset(vis,0,sizeof vis);
    turn = 1;
    while((k = dfs(s,inf)) != inf) {
        mf += k;
        turn++;
    }
    return mf;
}

void addedge(int u, int v, int _cap) {
    to[es] = v; nx[es] = head[u]; head[u] = es; cap[es] = _cap; fl[es++] = 0;
    to[es] = u; nx[es] = head[v]; head[v] = es; cap[es] = _cap; fl[es++] = 0;
}

int main() {
    while(scanf("%d %d",&n,&m) && n && m) {
        memset(head,0,sizeof head);
        es = 2;
        for(int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c); u--; v--;
            addedge(u, v, c);
        }
        s = 0; t = 1;
        maxflow();
        memset(ans,0,sizeof ans);
        dfsa(0);
        for(int i = 2; i < es; i++) {
            int u = to[i^1], v = to[i];
            if(ans[u] && !ans[v]) printf("%d %d\n",u+1,v+1);
        }
        printf("\n");
    }
}


