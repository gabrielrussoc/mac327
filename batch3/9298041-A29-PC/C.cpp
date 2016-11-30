#include <bits/stdc++.h>
#define pb push_back
#define free bobao
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 312345;
set<pii> forbid;
vector<int> adj[N];
set<int> free;
int comp, ones, n, m, k;

bool can(int u, int v) {
    if(u > v) swap(u,v);
    return forbid.find(pii(u,v)) == forbid.end();
}

void dfs(int u){
    vector<int> aux;
    for(int v : free) if(can(u,v)) aux.pb(v);
    for(int v : aux) free.erase(v);
    for(int v : aux) dfs(v); 
}

void fail(){
    puts("impossible");
    exit(0);
}

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        if(u > v) swap(u,v);
        forbid.insert(pii(u,v));
        if(u == 0) ones++;
    }
    if(n-1-ones < k) fail();
    for(int i = 1; i < n; i++) free.insert(i);
    for(int i = 1; i < n; i++) {
        if(can(0,i) && free.find(i) != free.end()) {
            dfs(i);
            comp++;
        }
    }
    if(!free.empty()) fail();
    if(comp > k) fail();
    puts("possible");
}

