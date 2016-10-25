#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 112345;

ll memo[N], n;
ll inf = N;
int visi[N];

ll dp(ll n) {
    if(n == 0) return 0;
    ll &me = memo[n];
    if(visi[n]) return me;
    visi[n] = 1;
    me = inf;
    for(ll i = 1; i*i*i <= n; i++)
        me = min(me, 1ll+dp(n-(i*i*i)));
    return me;
}

int main() {
    int tc = 1;
    while(scanf("%lld",&n) != EOF) {
        printf("Case #%d: %lld\n",tc++, dp(n));
    }
}

