#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 205;

int n, m, forbid[N][N], vis[N], comp[N][2], cs, id[N], ans[N];
bool memo[N][N], visi[N][N];

void fail(){
    puts("IMPOSSIBLE");
    exit(0);
}

void dfs(int u, int p, int c){
    if(vis[u]) { 
        if(vis[u] != c) fail();
        else return;
    }
    vis[u] = c;
    id[u] = cs;
    comp[cs][c-2]++;
    for(int v = 0; v < 2*n; v++)
        if(forbid[u][v] && v != p) 
            dfs(v, u, c^1);
}

bool dp(int i, int q) {
    if(i == cs) return q == n;
    bool &me = memo[i][q];
    if(visi[i][q]) return me;
    visi[i][q] = 1;
    return me = dp(i+1, q + comp[i][0]) | dp(i+1, q + comp[i][1]);
}

void mark(int c, int k){
    for(int i = 0; i < 2*n; i++) {
        if(id[i] == c && vis[i] == k+2)
            ans[i] = true;
    }
}

void rebuild(int i = 0, int q = 0){
    if(q == n) return;
    if(dp(i+1, q + comp[i][0])) {
        mark(i, 0);
        rebuild(i+1, q+comp[i][0]);
    } else {
        mark(i, 1);
        rebuild(i+1, q + comp[i][1]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u,&v); u--; v--;
        forbid[u][v] = forbid[v][u] = 1;
    }
    for(int i = 0; i < 2*n; i++) {
        if(!vis[i]) {
            dfs(i, -1, 2);
            cs++;
        }
    }
    if(dp(0,0)) {
        rebuild();
        for(int i = 0; i < 2*n; i++) if(ans[i]) printf("%d ", i+1);
        putchar('\n');
        for(int i = 0; i < 2*n; i++) if(!ans[i]) printf("%d ", i+1);
        putchar('\n');
    }
    else puts("IMPOSSIBLE");
}

