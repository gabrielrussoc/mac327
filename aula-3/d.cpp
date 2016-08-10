#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1000000007;

map<ll, ll> m;

ll fexp(ll x, ll e) {
    ll r = 1;
    while(e) {
        if(e&1) r = (x*r) % modn;
        x = (x*x) % modn;
        e >>= 1;
    }
    return r%modn;
}

int main() { 
    int n; ll x;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
    }
    ll ans = 1;
    ll d = 1;
    for(auto q : m) {
        ll p = q.first, k = q.second;
        ll f = fexp(p, k*(k+1ll)/2ll);
        ans = (fexp(ans,k+1) * fexp(f,d)) % modn;
        d = (d * (k+1ll)) % (modn-1);
    }
    cout << ans << endl;
}
