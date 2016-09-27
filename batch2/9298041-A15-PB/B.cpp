#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 1e6+7;
int l[N], r[N], M[N], vis[N];
vector<int> adj[N];
int k, p, x, q;

int dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for(int v : adj[u]) {
        if(M[v] == -1 || dfs(M[v])) {
            M[u] = v;
            M[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    while(scanf("%d %d",&k,&p) &&  k && p) {
        int ls = 0;
        for(int i = 0; i < k; i++) { 
            scanf("%d",&x);
            l[i] = ls;
            ls += x;
            r[i] = ls; 
        }
        for(int i = 0; i < ls+p; i++) { adj[i].clear(); M[i] = -1; }
        for(int i = 0; i < p; i++) {
            scanf("%d",&q);
            while(q--) {
                scanf("%d",&x); x--;
                for(int j = l[x]; j < r[x]; j++) {
                    adj[ls+i].pb(j);
                    adj[j].pb(ls+i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < ls; i++) {
            memset(vis,0,sizeof vis);
            if(dfs(i)) ans++;
        }
        if(ans == ls) {
            puts("1");
            for(int i = 0; i < k; i++) 
                for(int j = l[i]; j < r[i]; j++)
                    printf("%d%c",M[j]-ls+1," \n"[j==r[i]-1]);
        } else puts("0");
    }
}

