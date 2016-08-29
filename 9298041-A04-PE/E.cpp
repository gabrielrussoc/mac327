#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll modn = 1e9+7;

ll fexp(ll x, ll e) {
    ll r = 1;
    while(e) {
        if(e&1) r = (r*x) % modn;
        x = (x*x) % modn;
        e >>= 1;
    }
    return r % modn;
}

struct mod {
    ll x;
    mod (): x(0) {}
    mod(ll y): x(y%modn) {}
    mod operator+ (const mod &o) const {
        return (x + o.x)%modn;
    }
    mod operator- (const mod &o) const {
        return (modn + x - o.x) % modn;
    }
    mod operator* (const mod &o) const {
        return ((x%modn)*(o.x%modn))%modn;
    }
    mod operator/ (const mod &o) const {
        return (x * fexp(o.x,modn-2))%modn;
    } 
    mod operator^ (const mod &o) const {
        return fexp(x,o.x)%modn;
    }
};

mod acc (ll lq, ll rq){
    mod l = mod(lq-1), r = mod(rq);
    mod a = (l*(l+mod(1)))*mod((modn+1)/2);
    mod b = (r*(r+mod(1)))*mod((modn+1)/2);
    return b-a;
}

int main() {
    ll mm,nn;
    mod m,n;
    cin >> nn >> mm;
    m = mod(mm); n = mod(nn);
    mod ans = n*m;
    mod sum;
    mm = min(nn,mm);
    ll k = mm+1;
    for(ll i = 1; i*i <= nn; i++) {
        ll l, r;
        l = nn/(i+1) + 1; r = min(nn/i,mm);
        if(l > r) continue;
        k = min(k, l);
        sum = sum + (mod(i) * acc(l,r));
    }
    for(ll i = 1; i < k; i++)
        sum = sum + (mod(nn/i)*mod(i));
    cout << (ans-sum).x << endl;
}


