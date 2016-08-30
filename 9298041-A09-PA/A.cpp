#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;

vector<int> adj[N];
int cat[N], gr[N];
int n, m;

int dfs(int u, int p, int at, int maxi) {
    if(gr[u] == 1 && u) return maxi <= m;
    int ret = 0;
    for(int v : adj[u])
        if(v != p) {
            int loc;
            if (cat[v]) loc = at+1;
            else loc = 0;
            ret += dfs(v, u, loc, max(loc, maxi)); 
        }
    return ret;
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++) scanf("%d", cat+i);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d",&u, &v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        gr[u]++; gr[v]++;
    }
    printf("%d\n",dfs(0,0,cat[0],cat[0]));
}

