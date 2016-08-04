#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;

ll calc(ll t) {
    ll b = 64-__builtin_clzll(k);
    if(t < b) return 1ll<<t;
    return (1ll<<b) + max(t-b,0ll)*k;
}

int main(){
    scanf("%lld %lld",&n,&k);
    ll lo = 0, hi = n;
    while(lo < hi) {
        ll mid = (lo+hi)/2ll;
        if(calc(mid) >= n) hi = mid;
        else lo = mid+1;
    }
    printf("%lld\n",lo);
}
