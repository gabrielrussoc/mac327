#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 112345;
const int inf = INT_MAX;
ll f[N], tree[4*N], b[N], B, p;
int n, q;

void build(int k = 1, int l = 0, int r = n-1){
    if(l == r) tree[k] = 0;
    else {
        int m = (l+r)/2;
        build(2*k, l, m);
        build(2*k+1,m+1,r);
        tree[k] = 0;
    }
}

ll query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    if(l >= fl && r <= fr) return tree[k];
    if(r < fl || l > fr) return 0;
    int m = (l+r)/2;
    return ((query(fl,fr,2*k,l,m)*b[max(min(fr,r)-m,0)])%p + query(fl,fr,2*k+1,m+1,r))%p;
}

void update(int i, int val, int k = 1, int l = 0, int r = n-1){ 
    if(l == r) tree[k] = val;
    else {
        int m = (l+r)/2;
        if(i <= m) update(i,val,2*k,l,m);
        else update(i,val,2*k+1,m+1,r);
        tree[k] = ((tree[2*k]*b[r-m])%p + tree[2*k+1]) % p;
    }
}

int main() {
    while(scanf("%lld %lld %d %d",&B,&p,&n,&q) && B && p && n && q) {
        for(int i = 0; i < n; i++) f[i] = 0;
        b[0] = 1;
        for(int i = 1; i <= n; i++) b[i] = (b[i-1]*B) % p;
        build();
        while(q--) {
            char c;
            scanf(" %c",&c);
            int a, b;
            scanf("%d %d",&a,&b);
            if(c == 'E') update(a-1, b);
            else printf("%d\n",query(a-1,b-1));
        }
        puts("-");
    }
}

