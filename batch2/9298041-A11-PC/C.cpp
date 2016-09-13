#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
const int N = 33;
const double EPS = 1e-9;

map<string, int> m;
int n, es, turn, k;
int to[N*N], head[N], nx[N*N], wei[N*N], vis[N*N];

int dfs(int u, int f, double q) {
    if(u == turn-1 && f) return q > 1 + EPS;
    vis[f] = 1;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];       
        if(!vis[e]) if(dfs(u,e,wei[e])) return 1;
    }
    return 0;
}

int main() {
    int tc = 1;
    while(scanf("%d",&n) && n) {
        es = 2;
        memset(head,0,sizeof head);
        m.clear();
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            m[s] = i;
        }
        scanf("%d",&k);
        while(k--) {
            string s, t;
            double w;
            cin >> s >> w >> t;
            int u = m[s], v = m[t];
            vis[es] = 0;
            wei[es] = w; to[es] = v; nx[es] = head[u]; head[u] = es++;
        }
        for(turn = 1; turn <= n; turn++) {
            if(dfs(turn-1, 0, 1)) {
                printf("Case %d: Yes\n",tc++);
                break;
            }
        }
        if(turn == n+1)
            printf("Case %d: No\n",tc++);
    }
}

