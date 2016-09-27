#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int inf = INT_MAX;
const int N = 105;
const int M = 2*N*N;
int to[M], head[N], cap[M], fl[M], nx[M], vis[N], es;
int n, s, t, c;

int dfs(int u, int mini) {
    vis[u] = 1;
    if(u == t) return mini;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v] && cap[e]-fl[e]) {
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

int maxflow() {
    int ret = 0;
    while(true) {
        memset(vis,0,sizeof vis);
        int k = dfs(s, inf);
        if(k == inf) break;
        ret += k;
    }
    return ret;
}

int main() {
    int tc = 1;
    while(scanf("%d", &n) && n) {
        es = 2;
        memset(head,0,sizeof head);
        scanf("%d %d %d",&s,&t,&c); s--; t--;
        for(int i = 0; i < c; i++) {
            int u, v, w;
            scanf("%d %d %d",&u,&v,&w); u--; v--;
            to[es] = v; nx[es] = head[u]; cap[es] = w; fl[es] = 0; head[u] = es++;
            to[es] = u; nx[es] = head[v]; cap[es] = w; fl[es] = 0; head[v] = es++;
        }
        printf("Network %d\n",tc++);
        printf("The bandwidth is %d.\n\n",maxflow());
    }
}

