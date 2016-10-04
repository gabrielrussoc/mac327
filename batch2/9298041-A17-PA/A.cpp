#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2123;
int v[N], w[N], memo[N][N];
int n, s;
typedef long long ll;

int dp(int i, int at) {
    if(i == n) return 0;
    int &me = memo[i][at];
    if(me != -1) return me;
    me = dp(i+1,at);
    if(at+w[i] <= s) me = max(me, v[i]+dp(i+1,at+w[i]));
    return me;
}

int main() {
    scanf("%d %d",&s,&n);
    for(int i = 0; i < n; i++) scanf("%d %d",w+i,v+i);
    memset(memo,-1,sizeof memo);
    printf("%d\n",dp(0,0));
    
}

