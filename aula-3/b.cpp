#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 112345;
ll p[N], acc[N];
int prime[N], ps;

ll fi(ll n) {
    ll res = 1;
    while(n > 1) {
        ll k = p[n], e = 0;
        while(n%k == 0) {
            e++;
            n /= k;
        }
        res *= (k-1);
        for(int i = 0; i < e-1; i++) res *= k;
    }
    return res;
}

int main() {
    for(int i = 2; i < N; i++) {
        if(p[i]) continue;
        prime[ps++] = i;
        for(int j = i; j < N; j += i)
            p[j] = i;
    }   
    acc[1] = 0;
    for(int i = 2; i < N; i++) acc[i] = acc[i-1] + i-fi(i);
    int t;
    scanf("%d",&t);
    ll n;
    for(int tc = 1; tc <= t; tc++) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",tc,acc[n]);
    }
    
}
