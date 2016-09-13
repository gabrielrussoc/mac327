#include <bits/stdc++.h>
#define hash xablau
#define div corinthians
using namespace std;

typedef unsigned long long hash;
const int N = 1e5+7;

hash h[N], x[N];
hash X = 33;
int n, div[N], ds;
char s[N];

set<hash> p;
int ans;

hash calc (int l, int r) {
    return h[r+1] - x[r-l+1]*h[l];
}

void go(int k, int f) {
    for(int i = 0; i < n; i += k)
        if (calc(0,k-1) != calc(i,i+k-1)) return;
    if(!f) p.insert(calc(0,k-1));
    else ans += p.count(calc(0,k-1));
}

void solve (int f) {
    scanf (" %s", s);
    n = strlen(s);
    x[0] = 1;
    for(int i = 0; s[i]; i++) {
        x[i+1] = X * x[i];
        h[i+1] = h[i]*X + hash(s[i]-'a'+1);
    }
    
    ds = 0;
    for (int i = 1; i*i <= n; i++) {
        if(n%i) continue;
        div[ds++] = i;
        if(i*i != n) div[ds++] = n/i;
    }
    for(int i = 0; i < ds; i++) go(div[i],f);
}

int main() {
    solve(0);
    solve(1);
    printf("%d\n",ans);
}
