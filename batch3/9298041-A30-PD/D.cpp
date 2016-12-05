#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int N = 212345;
int n, m;
ll t[N], d[N], r[N], acc[N], bit[N][2];
int p[N], last, ans[N];
pli ord[N];

void update(int idx, ll val, int k){
    for(int i = idx+2; i < N; i += i&-i)
        bit[i][k] += val;
}

ll query(int idx, int k){
    ll ret = 0;
    for(int i = idx+2; i > 0; i -= i&-i)
        ret += bit[i][k];
    return ret;
}

bool comp(int i, int j){
    return d[i] < d[j];
}

void fix(ll d){
    while(last < n && ord[last].first <= d) {
        update(ord[last].second, -ord[last].first, 0);
        update(ord[last].second, -1, 1);
        last++;
    }
}

int calc(ll r, ll d){
    int lo = 0, hi = n; 
    while(lo < hi){
        int mid = (lo+hi)/2;
        ll q = query(mid, 0) - d * query(mid,1);
        if(q >= r) hi = mid;
        else lo = mid+1;
    }
    return lo == n ? -1 : lo;
}

int main() {
    scanf("%d %d",&m, &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", t+i);
        update(i, t[i], 0);
        update(i, 1, 1);
        ord[i] = pli(t[i], i);
    }
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld", d+i, r+i);
        p[i] = i;
    }
    sort(p, p+m, comp);
    sort(ord, ord+n);
    for(int i = 0; i < m; i++){
        ll dd = d[p[i]];
        ll rr = r[p[i]];
        fix(dd);
        ans[p[i]] = calc(rr, dd);
    }
    for(int i = 0; i < m; i++) printf("%d ",ans[i]+1);
    putchar('\n');
}

