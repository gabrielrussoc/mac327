#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1024;
const ll MOD = 1e6+3;

int t, n, m;
int lc[N], rc[N], key[N], sz[N], ts;
ll comb[N][N];

int add(int r, int val) {
    if(r == 0) {
        key[ts] = val;
        lc[ts] = rc[ts] = 0; 
        sz[ts] = 1;
        return ts++;
    }
    if(key[r] > val) lc[r] = add(lc[r], val);
    else rc[r] = add(rc[r], val);
    sz[r] = 1 + sz[lc[r]] + sz[rc[r]];
    return r;
}

ll calc(int r) {
    if(r == 0) return 1;
    ll rl = calc(lc[r]);
    ll rr = calc(rc[r]);
    int x = sz[lc[r]];
    int y = sz[rc[r]];
    return (comb[x+y][x] * rl * rr) % MOD;
}

void show(int r){
    if(r == 0) return;
    printf("%d (%d)\n",key[r],sz[r]);
    show(lc[r]);
    show(rc[r]);
}

int main() {
    scanf("%d",&t);
    
    for(int i = 0; i < N; i++) comb[i][0] = comb[i][i] = 1;
    for(int i = 1; i < N; i++)
        for(int j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;

    while(t--) {
        scanf("%d %d",&n,&m);
        int r = 0;
        ts = 1;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d",&x);
            r = add(r, x);
        }
        //show(r);
        printf("%lld\n", (comb[m][n] * calc(r)) % MOD);
    }
}

