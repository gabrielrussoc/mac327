#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 112345;
ll a[N], memo[N], f[N];
int n, g;

ll dp(int i) {
    if(i >= g) return 0;
    ll &me = memo[i];
    if(me != -1) return me;
    me = dp(i+1);
    int p = (a[i+1] == (a[i]+1));
    me = max(me, f[a[i]] * a[i] + dp(i+1+p));
    return me;
}

int main() {
    memset(memo,-1,sizeof memo);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) { scanf("%lld",a+i); f[a[i]]++; }
    sort(a,a+n);
    g = unique(a,a+n)-a;
    a[g] = -1;
    printf("%lld\n",dp(0));
}

