#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 112345;
int p[N], acc[N];

int query(int l, int r) {
    return acc[r] - acc[l-1];
}

int main() {
    for(int i = 2; i*i < N; i++) {
        if(p[i]) continue;
        for(int j = i*i; j < N; j += i)
            p[j] = i;
    } 
    acc[0] = acc[1] = 0;
    for(int i = 2; i < N; i++) acc[i] = acc[i-1] + !p[i];

    int t;
    scanf("%d", &t);
    int n, k;
    while(t--) {
        scanf("%d %d",&n, &k);
        ll ans = 0;
        for(int i = 2; i <= n; i++) {
            int lo = i, hi = n+1;
            while(lo < hi){
                int mid = (lo+hi)/2;
                if(query(i,mid) >= k) hi = mid;
                else lo = mid+1;
            } 
            if(lo == n+1) continue;
            ans += ll(n-lo+1);
        }
        printf("%lld\n",ans);
    }


}
