#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 112345;
const int inf = INT_MAX;
int v[N], tree[4*N], n, q, t;

int sgn(int x) {
    return (x > 0) - (x < 0);
}

void build(int k = 1, int l = 0, int r = n-1){
    if(l == r) tree[k] = sgn(v[l]);
    else {
        int m = (l+r)/2;
        build(2*k, l, m);
        build(2*k+1,m+1,r);
        tree[k] = tree[2*k] * tree[2*k+1];
    }
}

int query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    if(l >= fl && r <= fr) return tree[k];
    if(r < fl || l > fr) return 1;
    int m = (l+r)/2;
    return query(fl,fr,2*k,l,m) * query(fl,fr,2*k+1,m+1,r);
}

void update(int i, int val, int k = 1, int l = 0, int r = n-1){ 
    if(l == r) tree[k] = sgn(val);
    else {
        int m = (l+r)/2;
        if(i <= m) update(i,val,2*k,l,m);
        else update(i,val,2*k+1,m+1,r);
        tree[k] = tree[2*k] * tree[2*k+1];
    }
}

char show(int x) {
    if (x > 0) return '+';
    else if (x < 0) return '-';
    else return '0';
}

int main() {
    while(scanf("%d %d",&n,&q) != EOF) {
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        build();
        while(q--) {
            char c;
            scanf(" %c",&c);
            int a, b;
            scanf("%d %d",&a,&b);
            if(c == 'C') update(a-1, b);
            else printf("%c",show(query(a-1,b-1)));
        }
        putchar('\n');
    }
}


