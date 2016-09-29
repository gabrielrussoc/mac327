#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1e5+7;
const int inf = INT_MAX;
int to[N], head[N], cap[N], nx[N], fl[N], vis[N];
int n, es = 2, turn = 1;
int s = 0, t = 'Z'-'A';

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

int maxflow() {
    int mf = 0, k;
    while((k = dfs(s,inf)) != inf) {
        mf += k;
        turn++;
    }
    return mf;
}

void addedge(int u, int v, int _cap) {
    to[es] = v; nx[es] = head[u]; head[u] = es; cap[es] = _cap; fl[es++] = 0;
    to[es] = u; nx[es] = head[v]; head[v] = es; cap[es] = 0; fl[es++] = 0;
}

    int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        char u, v;
        int c;
        scanf(" %c %c %d", &u, &v, &c);
        addedge(u-'A', v-'A', c);
    }
    printf("%d\n",maxflow());
}

