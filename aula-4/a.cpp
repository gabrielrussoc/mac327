#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll fexp(ll x, ll e, ll m) {
    ll r = 1;
    while(e) {
        if(e&1) r = (r*x) % m;
        x = (x*x) % m;
        e >>= 1;
    }
    return r % m;
}

int main() {
    int t;
    ll b, e, m;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%lld %lld %lld",&b,&e,&m);
        printf("%d. %lld\n",tc,fexp(b,e,m));
    }
}
