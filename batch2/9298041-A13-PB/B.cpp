#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
int n, a, b, c, d;

int out(int x) {
    return (x < 1) || (x > n);
}

int main() {
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    int v1,v2,v4,v5;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        v1 = i;
        v2 = v1+b-c;
        v4 = v1+a-d;
        v5 = v1+a+b-c-d;
        if(out(v1) || out(v2) || out(v4) || out(v5)) continue;
        if(a + v2 + c != b + v4 + d) continue;
        if(a + v2 != d + v5) continue;
        if(b + v4 != c + v5) continue;
        ans += ll(n);
    } 
    printf("%lld\n",ans);
}

