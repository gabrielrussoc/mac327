#include <bits/stdc++.h>
#define pb push_back
#define div uasheush
using namespace std;

typedef long long ll;
#define double long double

const int N = 100;
double eps = 1e-9;
int p[N], ps, t; 
ll prime[N], pot[N], n, div, ans, loc;

void solve(ll k, int q, int e) {
    ll lq = 1;
    for(ll i = 1; i <= e; i++) {
        lq *= prime[q];
        if(k <= n/lq) {
            pot[q] = i;
            loc *= i+1;
            solve(k*lq, q+1, i);
            loc /= i+1;
            pot[q] = 0;
        } else {
            if(loc >= div) {
                if(loc == div) ans = min(ans, k);
                else ans = k;
                div = loc;
            }
            return;
        }
    }
}

int main() {
    for(int i = 2; i < N; i++) {
        if(p[i]) continue;
        prime[ps++] = i;
        for(int j = i; j < N; j += i)
            p[j] = i;
    }

    scanf("%d",&t);
    while(t--) {
        ans = LLONG_MAX;
        div = loc = 1;
        scanf("%lld",&n);
        solve(1, 0, 62);
        printf("%lld %lld\n",ans,div);
    }


}

