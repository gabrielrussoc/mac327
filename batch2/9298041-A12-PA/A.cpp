#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
int n, color[123];
vector<int> adj[123];

void fail(){
    puts("-1");
    exit(0);
}

void dfs(int u, int ls) {
    if(color[u] == ls) fail();
    if(color[u] == (ls^1)) return;
    color[u] = ls^1;
    for(int v : adj[u])
        dfs(v, ls^1);
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int j;
        while(scanf("%d",&j) && j) {
            j--;
            adj[i].pb(j);
            adj[j].pb(i);
        }
    }
    dfs(0,3);
    for(int i = 0; i < n; i++) printf("%d",color[i]&1);
    putchar('\n');
}

