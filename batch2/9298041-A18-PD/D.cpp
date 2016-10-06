#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 1123456;
int f[N], v[N], n, memo[N], visi[N];

int dp(int x) {
    if(x >= N || !f[x]) return 0;
    int &me = memo[x];
    if(visi[x]) return me;
    visi[x] = 1; 
    me = 1;
    for(int i = 2; i*x < N; i++) me = max(me, 1+dp(i*x));
    return me;
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",v+i);
        f[v[i]] = 1;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, dp(v[i]));
    printf("%d\n",ans);
}

