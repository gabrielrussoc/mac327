#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3007;
int n, m;
int d[N][N], r[N][N];
ll bit[N];
vector<int> v[N];
char s[N];

void upd(int idx, ll val) {
    for(int i = idx+2; i < N; i += i&-i)
        bit[i] += val;
}

ll qry(int idx) {
    ll ret = 0;
    for(int i = idx+2; i > 0; i -= i&-i)
        ret += bit[i];
    return ret;   
}

ll qry(int a, int b){
    a = max(a, 0);
    return qry(b) - qry(a-1);
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) {
        scanf(" %s", s);
        for(int j = m-1; j >= 0; j--) {
            if(s[j] == 'z') {
                r[i][j] = 1 + r[i][j+1];   
                d[i][j] = 1 + (i ? d[i-1][j+1] : 0);
            }
        }
    }

    ll ans = 0;
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            for(int x : v[i]) upd(x, -1);
            v[i].clear();
            if(r[i][j]) {
                upd(i, 1);
                v[min(n, i+r[i][j])].pb(i);
                int q = min(r[i][j], d[i][j]);
                ans += qry(i-q+1, i);
            }
        }
        for(int x : v[n]) upd(x, -1);
        v[n].clear();
    }
    printf("%lld\n",ans);
}
