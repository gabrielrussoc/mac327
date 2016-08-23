#include <bits/stdc++.h>
#define pb push_back
#define div uasheush
using namespace std;

typedef long long ll;

const int N = 100;
double eps = 1e-9;
int p[N], ps, t; 
ll prime[N], pot[N], n, div, ans, at;

void solve(ll k) {
    for(int i = 0; i < ps; i++)
        if(log(k) + log(prime[i]) <= log(n)+eps) {
            pot[i]++;
            at /= pot[i];
            at *= pot[i]+1;
            if(at >= div) {
                if(at > div) ans = k*prime[i];
                else ans = min(ans, k*prime[i]);
                div = at;
            }
            solve(k*prime[i]);
            at /= pot[i]+1;
            at *= pot[i];
            pot[i]--;
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
        div = at = 1;
        scanf("%lld",&n);
        solve(1);
        if(ans == LLONG_MAX) ans = 1;
        printf("%lld %lld\n",ans,div);
    }


}

