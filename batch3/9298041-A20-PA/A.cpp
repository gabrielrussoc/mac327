#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 112345;
const int inf = INT_MAX;
int v[N], tree[4*N], n, q, t;

void build(int k = 1, int l = 0, int r = n-1){
    if(l == r) tree[k] = v[l];
    else {
        int m = (l+r)/2;
        build(2*k, l, m);
        build(2*k+1,m+1,r);
        tree[k] = min(tree[2*k], tree[2*k+1]);
    }
}

int query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    if(l >= fl && r <= fr) return tree[k];
    if(r < fl || l > fr) return inf;
    int m = (l+r)/2;
    return min(query(fl,fr,2*k,l,m),query(fl,fr,2*k+1,m+1,r));
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d %d",&n,&q);
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        build();
        printf("Scenario #%d:\n",tc);
        while(q--) {
            int a, b;
            scanf("%d %d",&a,&b); a--; b--;
            printf("%d\n",query(a,b));
        }
    }
}

