#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    ll n, big, j;
    scanf("%lld",&n);
    ll ans = 0;
    for(j = 1, big = 1; big*10 <= n; big *= 10, j++);
    ans += (n-big+1)*j;
    ll pot = 10;
    for(ll i = 1; i < j; i++) {
        ans += (pot - pot/10) * i; 
        pot *= 10;
    }
    printf("%lld\n",ans);
    
}

