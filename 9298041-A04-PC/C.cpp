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

struct modd {
    ll x;
    modd () {}
    modd(ll y): x(y) {}
    modd operator+ (const modd &o) const {
        return (x + o.x)%modn;
    }
    modd operator- (const modd &o) const {
        return (modn + x - o.x) % modn;
    }
    modd operator* (const modd &o) const {
        return ((x%modn)*(o.x%modn))%modn;
    }
    modd operator/ (const modd &o) const {
        return (x * fexp(o.x,modn-2))%modn;
    } 
    modd operator^ (const modd &o) const {
        return fexp(x,o.x)%modn;
    }
};

int main() {
    ll aa, bb, nn, xx;
    modd a,b,n,x;
    cin >> aa >> bb >> nn >> xx;
    a = modd(aa); b = modd(bb); n = modd(nn); x = modd(xx);
    modd an = modd(fexp(aa,nn));
    if(aa == 1) cout << ((a^n)*x + b*n).x << endl;
    else cout << ((a^n)*x + (b*((a^n)-modd(1)))/(a-modd(1))).x << endl;
}

