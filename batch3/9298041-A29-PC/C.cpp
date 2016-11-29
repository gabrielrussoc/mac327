#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 312345;
set<pii> forbid;
vector<int> adj[N];
set<int> tree, free;

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v); u--; v--;
        if(u > v) swap(u,v);
        forbid.insert(pii(u,v));
    }
    for(int i = 1; i < n; i++) free.insert(i);
    tree.insert(0);
    for(int i = 0; i < n-1; i++) {
        for(int v : free) {
            for(int u : tree) {
                int uu = min(u,v);
                int vv = max(u,v);
                if(forbid.find(pii(uu,vv)) == forbid.end()) {

                }
            }
        }
    }
}

