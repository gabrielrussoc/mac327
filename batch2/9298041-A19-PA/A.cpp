#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200007;

int n, v[N], tree[4*N];
char s[7];

void build(int k = 1, int l = 0, int r = n-1) {
    if(l == r) tree[k] = v[l];
    else {
        int m = (l+r)/2;
        build(2*k, l, m);
        build(2*k+1,m+1,r);
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}

int query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    if(l >= fl && r <= fr) return tree[k];
    if(l > fr || r < fl) return 0;
    int m = (l+r)/2;
    return query(fl,fr,2*k,l,m) + query(fl,fr,2*k+1,m+1,r);
}

void update(int i, int val, int k = 1, int l = 0, int r = n-1) {
    if(l == r) tree[k] = val;
    else {
        int m = (l+r)/2;
        if(i <= m) update(i,val,2*k,l,m);
        else update(i,val,2*k+1,m+1,r);
        tree[k] = tree[2*k] + tree[2*k+1];
    } 
}

int main() {
    int tc = 1;
    bool blank = false;
    while(scanf("%d",&n) && n != 0) {
        if(blank) putchar('\n');
        blank = true;
        printf ("Case %d:\n", tc++);
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        build();
        while (scanf(" %s", s) && strcmp(s, "END")) {
            if(s[0] == 'M') {
                int l, r;
                scanf("%d %d",&l, &r); l--; r--;
                printf("%d\n",query(l,r));
            } else {
                int i, x;
                scanf("%d %d",&i,&x); i--;
                update(i,x);
            }
        }
    }
}

